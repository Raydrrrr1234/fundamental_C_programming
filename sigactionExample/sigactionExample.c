/* sigactionExample.c--
   AUTHOR:Ruikang Dai
   DATE:Thu Apr 16 07:31:34 EDT 2015
*/
#include <stdio.h>
// These are optional header files
//#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/wait.h>
//#include <string.h>
#include <signal.h>
#include <sys/types.h>

// When a SIGUSR1 signal arrives, set this variable
volatile sig_atomic_t usr_interrupt = 0;

void synch_signal(int sig) {
	usr_interrupt = 1;
}

// The child process executes this function
void child_function(void) {
	// Preform initialization.
	printf("Child: pid is %d\n", (int) getpid());

	// Let parent know you're done.
	kill(getppid(), SIGUSR1);

	// Continue with execution
	puts("Child: good bye");
	exit(0);
}

int main(int argn, char **argv) {

	// Check number of command-line arguments
	if (argn != 2) {

	}
	struct sigaction usr_action;
	sigset_t block_mask;
	pid_t child_id;

	// Establish the signal handler
	sigfillset(&block_mask);
	usr_action.sa_handler = synch_signal;
	usr_action.sa_mask = block_mask;
	usr_action.sa_flags = 0;
	sigaction(SIGUSR1, &usr_action, NULL);

	// Create the child process does not return
	child_id = fork();
	if (child_id == 0)
		child_function(); 
	// Busy wait for the child to send a signal
	while (!usr_interrupt);
	
	// Now continue excution
	puts("Program execution complete");

	return 0;
}
