// Aryan Patel, asp0144
// Recitation 6

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	
	pid_t pid;
	pid = fork();
	char *name;
	
	if (pid == 0) {
		printf("Child: %d started\n", getpid());
		printf("child: parent = %d\n", getpid());
		sleep(20);
		printf("child just woke up\n");
	}
	else if (pid > 0) {
		printf("parent: %dstarted\n", getpid());
	}
	else {
		perror("Fork error");
	}
	
	name = (pid == 0)?"child":"parent";
	printf("%s: terminating...\n", name);
	
	return 0;
	
}