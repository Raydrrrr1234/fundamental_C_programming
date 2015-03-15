/* simplechain.c--
	A program that creates a chain of "n" processes, where n is a command-line argument.
   AUTHOR:Ruikang Dai
   DATE:Sat Mar 14 15:20:24 EDT 2015
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
	for (i = 1; i < n; i++)
		if ((childpid = fork())) 
			break;
	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
	return 0;
}
