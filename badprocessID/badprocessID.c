/* badprocessID.c--
	What happens when the following program executes?
	The parent sets the "mypid" value to its process ID before the fork. When fork executes, the child gets a copy of the process address space, including all variables. Since the child does not reset mypid, the value of "mypid" for the child does not agree with the value returned by getpid.
   AUTHOR:Ruikang Dai
   DATE:Sat Mar 14 15:15:13 EDT 2015
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argn, char **argv) {
	pid_t childpid;
	pid_t mypid;

	mypid = getpid();
	childpid = fork();
	if (childpid == -1) {
		perror("Failed to fork");
		return 1;
	}
	if (childpid == 0)
		printf("I am child %ld, ID = %ld\n", (long)getpid(), (long)mypid);
	else
		printf("I am parent %ld, ID = %ld\n", (long)getpid(), (long)mypid);
	return 0;
}
