#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main(void) {
    char s1[10] = "avalanche", s2[10];
    int pipefd[2];
   	int cpid;

    if (pipe(pipefd) != 0) {
        printf("Some error occured!\n");
        exit(1);
    }
    
    cpid = fork();
    if (cpid == 0) {
    	// reading from a child process
    	close(pipefd[1]);		 // closing the unused writing end
    	read(pipefd[0], s2, 10); // reading from the reading end
    	close(pipefd[0]);		 // closing the reading end
    	printf("Child has read the string: %s\n", s2);
    }
    else {
    	// writing from parent process
    	close(pipefd[0]);         // closing the unused reading end
    	write(pipefd[1], s1, 10); // writing to the write end
    	close(pipefd[1]);		  // closing the write end
    }
    
    return 0;
}
