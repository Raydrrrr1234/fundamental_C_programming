/* systemEx6.c-- fork_exp.c
	Accept a filename from the command line.
	Open filename for reading,
	Set stdin to refer to filename,
	Process creates a copy of itself(i.e. child process),
	Child switches to the "cat" program;
	Parents waits for the child to die.

   AUTHOR:Ruikang Dai
   DATE:Sat Feb 28 22:42:27 EST 2015
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

int main(int argn, char **argv) {
	int child_id;
	char *filename;
	int status;
	pid_t whodied;
	FILE *infile;

	if(argn != 2) {
		fprintf(stderr, "usage %s <file for reading>\n", argv[0]);
		exit(-1);
	}
	else {
		infile = freopen(argv[1], "r", stdin);
		if(!infile) {
			fprintf(stderr, "Couldn't open file %s!\n", argv[1]);
			perror("fork_exp");
			exit(errno);
		}
	}
	printf("File opened successfully!\n");
	child_id = fork();

	if(child_id) {
		printf("I'm the parent. \n");
		whodied = wait(&status);
		printf("Parent: Child %d exited", whodied);
		if(!WIFEXITED(status)) {
			printf("abnormally!\n");
		}
		else {
			printf("with status %d.\n", WEXITSTATUS(status));
		}
		return 0;
	}
	else {
		printf("I'm the child.\n");
		execlp("cat", "cat", NULL);
		printf("This statement is never reached.\n");
	}
}
