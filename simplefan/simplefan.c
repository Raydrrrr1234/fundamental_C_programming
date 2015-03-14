/* simplefan.c--
	A program that creates a fan of "n" processes where "n" is passed as a command-line argument.
   AUTHOR:Ruikang Dai
   DATE:Sat Mar 14 15:28:42 EDT 2015
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argn, char **argv) {
	pid_t childpid = 0;
	int i, n;
	// Check for valid number of command-line arguments
	if (argn != 2) {
		fprintf(stderr, "Usage: %s processes\n", argv[0]);
		return 1;
	}
	n = atoi(argv[1]);
	for (i = i; i < n; i++) 
		if ((childpid = fork()) <= 0) 
			break;
	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
	return 0;
}
