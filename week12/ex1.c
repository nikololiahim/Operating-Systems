#include <stdio.h>
#include <stdlib.h>
#define N 20

int main() {
	FILE* rand = fopen("/dev/random", "r");
	FILE* out = fopen("ex1.txt", "w");
	int i = 0;
	while (i < 20) {
		int c = fgetc(rand);
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
			fprintf(out, "%c", c);
			++i;
		}
	}
	fclose(rand);
	fclose(out);
	return 0;
}
