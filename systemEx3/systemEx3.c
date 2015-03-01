/* systemEx3.c--
   AUTHOR:Ruikang Dai
   DATE:Tue Feb 24 19:18:35 EST 2015
*/
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argn, char **argv) {
	// The path at which to create the new file.
	char * path = argv[1];
	// The permissions for the new file.
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	// Create the file.
	int fd = open(path, O_WRONLY | O_EXCL | O_CREAT, mode);
	if (fd == -1) {
	// An error occurred. Print an error message and bail.
		perror("open");
		return 1;
	}
	return 0;
}
