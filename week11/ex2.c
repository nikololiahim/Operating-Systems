#include <stdio.h>
#include "stdlib.h"
#include <unistd.h>


int main(){
	
	char buf[20];
	char* hello = "Hello";
	setvbuf( stdin, buf, _IOFBF, 20 );

	while (*hello != 0) {
		printf("%c", *hello);
		sleep(1);
		hello++;
	}
	
	return 0;
}
