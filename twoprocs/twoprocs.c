/* twoprocs.c--
	After fork in the following program, the parent and child output their respective process IDs.
   AUTHOR:Ruikang Dai
   DATE:Sat Mar 14 15:11:57 EDT 2015
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argn, char **argv) {
	pid_t childpid;
	
	childpid = fork();
	if (childpid == -1) {
		perror("Failed to fork");
		return 1;
	}
	if (childpid == 0) 
		printf("I am child %ld\n", (long)getpid());
	else
		printf("I am parent %ld\n", (long)getpid());
	return 0;
}
