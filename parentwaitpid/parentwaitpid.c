/* parentwaitpid.c--
	Describe the possible forms of the output from the following program:
	Because none of the forked children are parents, their wait function returns –1 and sets errno to ECHILD. They are not blocked by the second for loop. Their identification messages may appear in any order. The message from the original process comes out at the very end after it has waited for all of its children.
   AUTHOR:Ruikang Dai
   DATE:Sat Mar 14 17:21:58 EDT 2015
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argn, char **argv) {
	pid_t childpid;

	childpid = fork();
	if (childpid == 0)
		fprintf(stderr, "I am child %ld\n", (long)getpid());
	else if (wait(NULL) != childpid)
		fprintf(stderr, "A signal must have interrupted the wait!\n");
	else
		fprintf(stderr, "I am a parent %ld with child %ld\n", (long)getpid(), (long)childpid);
	return 0;
}
