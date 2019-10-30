#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char line[100] = "a";
	printf("Type q and press Enter to exit.\n");
	printf(">>>");
	fgets(line, 100, stdin);
	while (strcmp(line, "q\n")) {
		printf(">>>");
		system(line);
		fgets(line, 100, stdin);
	}
	return 0;
}
