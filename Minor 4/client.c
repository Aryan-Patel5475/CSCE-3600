#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

void client_socket(FILE *fp, int sockfd, const struct sockaddr *pservaddr, socklen_t servlen) {
	int n;
	char sendline[] = "PING\n", recvline[21];
	suseconds_t min = 9000000, max = 0, avg = 0;
	double sent = 0, received = 0;
	
	for (int i = 0; i < 10; i++) {
		struct timeval begin, end; 
		gettimeofday(&begin, NULL);
		sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);
		sent++;
		n = recvfrom(sockfd, recvline, 20, 0, NULL, NULL);
		gettimeofday(&end, NULL);
		recvline[n] = '\0';
		
		printf("%2d: Sent... ", i+1);
		struct timeval diff;
		diff.tv_sec = 0;
		diff.tv_usec = (end.tv_sec - begin.tv_sec) * 1000000 + end.tv_usec - begin.tv_usec;
		suseconds_t usec = diff.tv_usec;
		if (n >= 0) {
			printf("RTT=0.%ld000 ms\n", usec);
			received++;
			min = (usec < min)? usec : min;
			max = (usec > max)? usec : max;
			avg = avg + usec;
		}
		else {
			printf("Timed out\n");
		}
	}
	
	double average = (double)avg/received;
	printf("%d pkts xmited, %d pkts rcvd, %d%% pkt loss\nmin: %.3f ms, max: %.3f ms, avg: %.3f ms\n", (int)sent, (int)received, (int)(100*(sent-received)/sent), (double)min/1000, (double)max/1000, average/1000);
} 

int main(int argc, char **argv)
{
	int sockfd;
	struct sockaddr_in servaddr;
	
	if (argc != 3) {
		printf("usage : ./client <hostname> <port>\n");
		exit(1);
	}
	
	bzero(&servaddr, sizeof(servaddr));
	struct hostent *hosten;
	hosten = gethostbyname(argv[1]);
	if (hosten == NULL) {
		printf("hostname not found\n");
		return 0;
	}
	
	memcpy(&servaddr.sin_addr, hosten->h_addr_list[0], hosten->h_length);
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd == 0) {
		perror("socket failed\n");
		return 0;
	}
	
	struct timeval tv;
	tv.tv_sec = 1;
	tv.tv_usec = 0;
	if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
		perror("setsockopt error\n");
		return 0;
	}
	
	client_socket(stdin, sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	
	return 0;
}
