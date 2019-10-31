
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include "string.h"


int main(int argc, char const *argv[])
{
	struct stat file1;
	stat("ex1.txt", &file1);
	int fd1 = open( "ex1.txt", O_RDWR);
	int fd2 = open( "ex1.memcpy.txt", O_RDWR);

	ftruncate(fd2, file1.st_size);

	char *from = mmap(NULL, file1.st_size ,
						 PROT_READ,
						 MAP_SHARED, fd1, 0);
	char *to = mmap(NULL, file1.st_size ,
						 PROT_WRITE,
						 MAP_SHARED, fd2, 0);

	memcpy(to, from, file1.st_size);	


	close(fd1);
	close(fd2);

	return 0;
}
