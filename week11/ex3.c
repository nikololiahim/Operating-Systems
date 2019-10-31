#include <stdio.h>
#include <unistd.h>

void program1() {
 printf("Hello");
 fork();
 printf("\n");

}

void program2() {
 printf("Hello\n");
 fork();
 printf("\n");
}


int main() {

	int n;
	scanf("%d", &n);
	
	if (n == 1) {
		program1();
	}
	else if (n == 2) {
		program2();
	}
	else {
		printf("No such program!\n");
	}
} 
