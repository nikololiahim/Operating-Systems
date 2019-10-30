#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	for (int i = 0; i < 5; ++i) {
		int pid = fork();
		sleep(3);
	}	
	printf("Done\n");
	return 0;
} 
