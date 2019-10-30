#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main(void) {
	
	int cpid = fork();
	if (cpid == 0) {
		while (1) {
			sleep(1);
			printf("I'm alive!\n");
		}
	}
	else {
		sleep(10);
		kill(cpid, SIGTERM);
	}
	return 0;
}

