#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <arpa/inet.h>


#define MAXLINE 4096

void server_socket(int sockfd, struct sockaddr *pcliaddr, socklen_t clilen)
{
	int n;
	socklen_t len;
	char mesg[] = "PONG\n";
	
	printf("[server]: ready to accept data...\n");
	srand(time(0));
	
	for( ; ; ) {
		len = clilen;
		n = recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);
		
		printf("[client]: %s", mesg);
		
		int rand_num = rand()%10;
		
		if (rand_num < 3) {
			printf("[server]: dropped packet\n");
		}
		else {
			sendto(sockfd, mesg, n, 0, pcliaddr, len);
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("usage: ./server <port>\n");
		exit(EXIT_FAILURE);
	}
	
	int sockfd;
	struct sockaddr_in servaddr,cliaddr;
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd == 0) {
			perror("socket failed\n");
			return -1;
	}
	
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));
	
	if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) // bind socket to address and port number
	{
		perror("bind failure\n");
		return -1;
	}
	
	server_socket(sockfd, (struct sockaddr *) &cliaddr, sizeof(cliaddr));
	
	return 0;
}
