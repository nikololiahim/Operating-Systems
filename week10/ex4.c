#include <stdio.h>
#include <dirent.h>
#define SIZE 1000000
int main() {

	FILE* fp = fopen("ex4.txt", "w");

	DIR* dirp = opendir("tmp");
	if (dirp == NULL) { return (0xF); }
	int inodes[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		inodes[i] = 0;
	}
	
	struct dirent* dp;
	while ( (dp = readdir(dirp)) != NULL) {
		unsigned int inode = (unsigned int)dp->d_ino;
		++inodes[inode];
		if (inodes[inode] > 1) {
			fprintf(fp,"%d: %s ", inode, dp->d_name);
		}
	}

	


	return 0;
}
