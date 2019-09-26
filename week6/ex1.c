#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main(void) {
    char s1[10] = "avalanche", s2[10];
    int pipefd[2];

    if (pipe(pipefd) != 0) {
        printf("Some error occured!\n");
        exit(1);
    }
    
    write(pipefd[1], s1, 10);
    read(pipefd[0], s2, 10);
    close(pipefd[0]);
    close(pipefd[1]);

    printf("s1: %s\ns2: %s\n", s1, s2);
    
    
    return 0;
}
