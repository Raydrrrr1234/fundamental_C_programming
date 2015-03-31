/* Async_signal.c--
   AUTHOR:Ruikang Dai
   DATE:Tue Mar 31 18:29:10 EDT 2015
*/
#include <stdio.h>
// These are optional header files
//#include <errno.h>
//#include <stdlib.h>
#include <unistd.h>
//#include <sys/wait.h>
//#include <string.h>
#include <signal.h>
void sig_handler(int signo) {

	if (signo==SIGINT)
		//printf("received SIGINT\n");
		write(0,"received SIGINT\n",17);
}

int main(int argn, char **argv) {

	// Check number of command-line arguments
	if (signal(SIGINT,sig_handler) == SIG_ERR)
		//printf("\n can't catch SIGINT\n");
		write(0,"\ncan't catch SIGINT\n", 17);
	// Wait so that we can easily issue a signal to this process
	while(1)
		sleep(1);
	return 0;
}
