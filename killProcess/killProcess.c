/* killProcess.c--
	A simple program to test the funtion:
		#include <signal.h>
		int kill(pid_t pid, int sig);
   AUTHOR:Ruikang Dai
   DATE:Sun Mar 15 13:19:51 EDT 2015
*/
#include <stdio.h>
// These are optional header files
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/wait.h>
//#include <string.h>
#include <signal.h>
int main(int argn, char **argv) {

	// Check number of command-line arguments
//	if(argn != 2) {

//	}
	if (kill(getppid(), SIGKILL) == -1)
		perror("Failed to kill");
	return 0;
}
