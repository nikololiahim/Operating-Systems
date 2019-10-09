#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define TIME 10
#define MB (1024*1024)

int main(void) { 
	char** mem = (char**) malloc(TIME * sizeof (char*));
	 
	if (mem != NULL) {
		for (int i = 0; i < TIME; ++i) {
			mem[i] = (char*) malloc(2000*MB * sizeof *(mem[i]));
			memset(mem[i], 0, 2000*MB);
			
			if (mem[i] != NULL) {
				sleep(1);
			}
			else {
				printf("Allocation failure #%d\n", i+1);
				break;
			}
		}
	}
	else {
		printf("Allocation failure #0\n");
	}
	return 0;
}
