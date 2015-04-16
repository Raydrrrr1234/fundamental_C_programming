/* Pipes.c--
   AUTHOR:Ruikang Dai
   DATE:Thu Apr 16 15:27:56 EDT 2015
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
	int fds[2];
	pid_t pid;
	// Create a pip. File descriptors for the two ends of the pipe are placed in fds.
	pipe(fds);
	// fork a child process
	pid = fork();

	if (pid == (pid_t) 0) {
		// This is the child process.
		// Close the write end of
		// the file descriptor.
		close (fds[1]);
		// Connect the read end of the pipe to standard input
		dup2(fds[0], STDIN_FILENO);
		// Replace the child process with the "rev" program
		execlp("rev", "rev", 0);
	}
	else {
		// This is the parent process.
		FILE * stream;
		// Close the read end of the file descriptor
		close (fds[0]);
		stream = fdopen(fds[1], "w");
		fprintf(stream, "123456789\n");
		fflush(stream);
		close(fds[1]);
		// Wait for the child process to finish.
		waitpid(pid, NULL, 0);
	}
	return 0;
}
