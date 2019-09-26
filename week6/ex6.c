#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {

	int pipefd[2];
	
	int cpid = fork();
	int cpid2;
	
	if (cpid == 0) {
		// child 1	
		int spid;
		read(pipefd[0], &spid, sizeof spid);
		printf("First child: successfully acquired pid of the second child\n");
		sleep(5);
		printf("Sending SIGSTOP to the second child...\n");
		sleep(5);
		kill(spid, SIGSTOP);
		sleep(5);
	}
	else {
		cpid2 = fork();
		if (cpid2 == 0) {
			// child 2
			while(1) {
				printf("Child 2 is alive!\n");
				sleep(1);
			}
		}
		else {
			// main process
			printf("Main process: sending second child's pid to the first child...\n");
			write(pipefd[1], &cpid2, sizeof cpid2);
			waitpid(cpid2, NULL, 0);
		}
	}
	return 0;
}

