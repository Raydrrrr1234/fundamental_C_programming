/* blocktest.c--
	A program that blocks and unblocks SIGINT.
	Also calculate the the sum of the second argument of the program.
   AUTHOR:Ruikang Dai
   DATE:Sun Mar 15 22:16:03 EDT 2015
*/
#include <stdio.h>
// These are optional header files
//#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/wait.h>
//#include <string.h>
#include <signal.h>
int main(int argn, char **argv) {

	// Check number of command-line arguments
	if (argn != 2) {
		fprintf(stderr, "Usage: %s repeatfactor\n", argv[0]);
		return 1;
	}
	while (1) {
		if (sigprocmask(SIG_BLOCK, &intmask, NULL) == -1)
        		break;
        	fprintf(stderr, "SIGINT signal blocked\n");
        	for (i = 0; i < repeatfactor; i++)
        		y += sin((double)i);
        	fprintf(stderr, "Blocked calculation is finished, y = %f\n", y);
        	if (sigprocmask(SIG_UNBLOCK, &intmask, NULL) == -1)
        		break;
        	fprintf(stderr, "SIGINT signal unblocked\n");
        	for (i = 0; i < repeatfactor; i++)
        		y += sin((double)i);
        	fprintf(stderr, "Unblocked calculation is finished, y=%f\n", y);
	}
	perror("Failed to change signal mask");
	return 1;
}
