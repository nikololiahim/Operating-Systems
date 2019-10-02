#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	long long int n;
	printf("Type value of N:\n");
	scanf("%lld", &n);
	
	while (n <= 0) {
		printf("N should be greater than zero! Try again:\n");
		scanf("%lld", &n);
	}
	
	int* arr = (int*) malloc(n * sizeof *arr);
	arr[0] = 0;
	
	if (arr != NULL) {
	
		// Filling the array with numbers
		for (int i = 1; i < n; ++i) {
			arr[i] = arr[i-1] + 1;
		}
		
		// Printing the array
		printf("Here is the array:\n");
		for (int i = 0; i < n; ++i) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		
		// Deallocationg the memory
		free(arr);
	}
	else {
		printf("Memory allocation failure.\n");
	}
	
	return 0;
}
