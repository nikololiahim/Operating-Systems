#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 10
#define SMALLER_SIZE 5
#define BIGGER_SIZE 15

int min(size_t a, size_t b) {
	return (a < b? a : b);
}


// there is no portable way to determine the amount of memory allocated to ptr, 
// that's why I decided to introduce the old_size argument
void* my_realloc(void* ptr, size_t old_size, size_t new_size) {
	if (ptr == NULL) {
		return malloc(new_size);
	}
	if (new_size == 0) {
		free(ptr);
		return NULL;
	}
	void* new = malloc(new_size);
	if (new != NULL) {
		memcpy(new, ptr, min(old_size, new_size));
		free(ptr);
	} 
	else {
		return NULL;
	}
	return new;
}


int main(void) {
	// allocating memory
	int* arr = (int*) my_realloc(NULL, 0, SIZE * sizeof(*arr));
	
	if (arr != NULL) {
		// initializing with dummy values
		for (int i = 0; i < SIZE; ++i) {arr[i] = 228;}
	
		// printing to make sure everything is fine
		for (int i = 0; i < SIZE; ++i) {printf("%d ", arr[i]);}
		printf("\n");
		
		// shrinking the allocated memory
		arr = (int*) my_realloc(arr, SIZE * sizeof(*arr), SMALLER_SIZE * sizeof(*arr));
		
		if (arr != NULL) {
			for (int i = 0; i < SMALLER_SIZE; ++i) {printf("%d ", arr[i]);}
			printf("\n");
		}
		else {
			printf("Allocation failure!\n");
			return 1;
		}		
		
		// expanding the allocated memory
		arr = (int*) my_realloc(arr, SMALLER_SIZE * sizeof(*arr), BIGGER_SIZE * sizeof(*arr));
		if (arr != NULL) {
			for (int i = 0; i < BIGGER_SIZE; ++i) {printf("%d ", arr[i]);}
			printf("\n");
		}
		else {
			printf("Allocation failure!\n");
			return 1;
		}
		
		// freeing should be successful because my_realloc() calls malloc (setting new_size to 0 implies freeing arr)
		my_realloc(arr, 0, 0);
		
	}
	else {
		return 1;
	}
	
	
	return 0;
}
