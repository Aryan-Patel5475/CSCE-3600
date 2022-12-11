// Aryan Patel, asp0144
// Recitation 6

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	
	pid_t pid;
	pid = fork();
	
	if ((pid = fork()) < 0) {
		perror("fork error");
	} 
	else if (pid == 0) {
		exit(0);
	}
	else if (pid > 5) {
		sleep(5);
		system("ps -e -o pid,ppid,stat,user,cmd | grep $USER");
	}
	
	return 0;
}