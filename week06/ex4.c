#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

// if you compile this program, run it in the background and then
// write a command 'kill -SIGUSR1 <pid>', it will print the message
// 'The signal SIGUSR1 has been intercepted!'

void action_on_sigkill(int);
void action_on_sigstop(int);
void action_on_sigusr1(int);

int main(void) {
	fflush(stdout);
	
	while (1) {
		struct sigaction act_on_sigkill = {action_on_sigkill};
		struct sigaction act_on_sigstop = {action_on_sigstop};
		struct sigaction act_on_sigusr1 = {action_on_sigusr1};
 		sigaction(SIGKILL, &act_on_sigkill, NULL);
 		sigaction(SIGSTOP, &act_on_sigstop, NULL);
 		sigaction(SIGUSR1, &act_on_sigusr1, NULL);
	}
	return 0;
}

void action_on_sigkill(int signal) {
	printf("\nThe signal SIGKILL has been intercepted!\n");
	fflush(stdout);
	exit(signal);
}

void action_on_sigstop(int signal) {
	printf("\nThe signal SIGSTOP has been intercepted!\n");
	fflush(stdout);
	exit(signal);
}

void action_on_sigusr1(int signal) {
	printf("\nThe signal SIGUSR1 has been intercepted!\n");
	fflush(stdout);
	exit(signal);
}
