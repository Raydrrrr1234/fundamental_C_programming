/* fanwaitmsg.c--
	The following program creates a process fan. All the forked processes are children of the original process. How are the output messages ordered??
	Because none of the forked children are parents, their wait function returns –1 and sets errno to ECHILD. They are not blocked by the second for loop. Their identification messages may appear in any order. The message from the original process comes out at the very end after it has waited for all of its children.
   AUTHOR:Ruikang Dai
   DATE:Sat Mar 14 17:29:01 EDT 2015
*/
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argn, char **argv) {
	pid_t childpid = 0;
	int i,n;
	// Check number of command-line arguments
	if (argn != 2) {
		fprintf(stderr, "Usage: %s processes\n", argv[0]);
		return 1;
	}
	n = atoi(argv[1]);
	for (i = 1; i < n; i++)
		if ((childpid = fork()) <= 0) 
			break;
	while (1) {
		childpid = wait(NULL);
		if ((childpid == -1) && (errno != EINTR))
			break;
	}
	fprintf(stderr, "I am process %ld, my parent is %ld\n", (long)getpid(), (long)getppid());
	return 0;
}
