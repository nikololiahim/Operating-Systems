#include <stdio.h>
#include <string.h>


int main() {
	char string[] = "Hello World!";
	for (int i = 0; i < strlen(string); ++i) {
		printf("%c", string[i]);
	}
	printf("\n");

	return 0;
}
