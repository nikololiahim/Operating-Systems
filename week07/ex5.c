#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char** s =  (char**) malloc(sizeof s); // allocating memory for s
	char foo[] = "Hello World";
	*s = foo; // now this assignment is legal
	printf("s is %s\n", *s); // this line didn't cause segfault, but it's better to have *s here to have a meaningful result
	s[0] = foo;
	printf("s[0] is %s\n", s[0]);
	
	
	return 0;
}
