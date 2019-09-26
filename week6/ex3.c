#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void action(int);

int main(void) {
	printf("Press Ctrl + C:	");
	fflush(stdout);
	
	while (1) {
		struct sigaction act = {action};
		sigaction(SIGINT, &act, NULL);
	}
	return 0;
}

void action(int signal) {
	printf("\nThe signal SIGINT has been intercepted!\n");
	fflush(stdout);
	exit(signal);
}
