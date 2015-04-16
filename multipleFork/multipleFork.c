/* multipleFork.c--
   AUTHOR:Ruikang Dai
   DATE:Thu Apr 16 07:46:08 EDT 2015
*/
#include <stdio.h>
// These are optional header files
//#include <errno.h>
//#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
//#include <string.h>
//#include <signal.h>
#include <sys/types.h>
int main(int argn, char **argv) {

	// Check number of command-line arguments
	if (argn != 2) {

	}
	pid_t mypid, childpid;
	int status;

	// What's our pid?
	mypid = getpid();
	printf("Parent process. My pid is %d.\n", mypid);

	// Create the child
	if (childpid == -1) {
		perror("Cannot proceed. fork() error");
		return 1;
	}

	if (childpid == 0) {
		// Child process "Child 1" 
		printf("Child 1: I inherited my parent's pid as %d.\n", mypid);

		// Get our pid
		mypid = getpid();
		printf("Child 1: getppid() tells my parent is %d. My own pid instead is %d.\n", (int)getppid(), mypid);

		// Forks another child
		childpid = fork();
		if (childpid == -1) {
			perror("Cannot proceed. fork() error");
			return 1;
		}

		if (childpid == 0) {
			// This is the child of the first child, thus "Child 2"
			printf("Child 2: I inherted my parent's PID as %d.\n", mypid);

			mypid = getpid();
			if (childpid == -1) {
				perror("Cannot proceed. fork() error");
				return 1;
			}

			if (childpid == 0) {
			// "Child 3" sleeps 30 seconds then terminates 12,
			// Hopefully before its parent "Child 2"

				printf("Child 3: I inherited my parent's PID as %d.\n", mypid);

				mypid = getpid();
				printf("Child 3: my parent is %d. My own pid is %d.\n", (int)getppid(), mypid);
				sleep(30);
				return 12;
			} 
			else return 15; // the parent "Child 2" suddenly return 15
		}
		else {
			// This is still "Child 1", which waits for its child to exit
			while (waitpid(childpid, &status, WNOHANG) == 0) sleep(1);

			if (WIFEXITED(status))
				printf("Child 1: Child 2 exited with exit status %d.\n", WEXITSTATUS(status));
			else printf("Child 1: child has not terminated correctly.\n");
		}
	}
	else {
		// Then we are the parent process, "Parent"
		printf("Parent: fork() successful. My child's PID is %d\n", childpid);

		// Wait for the child to terminate and report about that
		wait(&status);
		if (WIFEXITED(status))
			printf("Parent: child has exited with status %d.\n", WEXITSTATUS(status));
			else printf("Parent: child has not terminated normally.\n");
	}

	return 0;
}
