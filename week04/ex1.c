#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	int n = 9000;
	int pid = fork();
	if (pid > 0) {
		printf("Hello from parent %d\n", pid - n);
	}
	else if (pid == 0){
		printf("Hello from child %d\n", pid);
	}
	else {
		printf("Failed to create a new process!\n");
	}
	return 0;
}
