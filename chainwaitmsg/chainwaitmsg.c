/* chainwaitmsg.c--
	The following program creates a process chain. Only one forked process is a child of the original process. How are the output messages ordered?

   AUTHOR:Ruikang Dai
   DATE:Sat Mar 14 17:39:36 EDT 2015
*/
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argn, char **argv) {
	pid_t childpid;
	int i, n;
	pid_t waitreturn;
	// Check number of command-line arguments
	if (argn != 2) {
		fprintf(stderr, "Usage: %s processes\n", argv[0]);
		return 1;
	}
	n = atoi(argv[1]);
	for (i = 1; i < n; i++)
		if (childpid = fork())
			break;
	while (childpid != (waitreturn = wait(NULL)))
		if ((waitreturn == -1) && (errno != EINTR))
			break;
	fprintf(stderr, "I am process %ld, my parent is %ld\n", (long)getpid(), (long)getppid());
	return 0;
}
