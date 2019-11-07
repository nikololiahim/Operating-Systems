#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


#define INIT_CAPACITY 16

typedef struct {
	size_t size, capacity;
	char* str;
} chr_list;

void init_chr_list(chr_list* lst) {
	lst->size = 0;
	lst->capacity = INIT_CAPACITY;
	lst->str = (char*) calloc(lst->capacity, sizeof *(lst->str));
}

void lst_append(chr_list* lst, char c) {
	if (lst->size + 1 == lst->capacity) {
		lst->capacity *= 2;
		lst->str = (char*) realloc(lst->str, sizeof *(lst->str) * lst->capacity);
	}
	lst->str[lst->size] = c;
	lst->str[lst->size+1] = '\0';
	lst->size += 1;
}

int main(int argc, char** argv) {

	int append = 0;
	int filestart = 1;
	int flags = O_WRONLY | O_TRUNC;
	
	if (strcmp(argv[1], "-a") == 0) {
		append = 1;
		filestart = 2;
		flags = O_WRONLY | O_APPEND;
	}
	
	chr_list buf;
	init_chr_list(&buf);	
	int c;
	int file_num = argc - filestart;
	
	// collecting input
	while ( (c = fgetc(stdin)) != EOF) {
		lst_append(&buf, c);
	}
	
	
	// writing to files
	write(fileno(stdout), buf.str, buf.size);
	
	for (int i = 0; i < file_num; ++i) {
		int fd = open(argv[i+filestart], flags);
		printf("writing to %d\n", fd);
		write(fd, buf.str, buf.size);
		close(fd);
	}
	
	
	return 0;
}
