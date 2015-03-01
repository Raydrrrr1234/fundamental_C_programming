/* handleSignals.c--
   AUTHOR:Ruikang Dai
   DATE:Tue Feb 24 20:46:35 EST 2015
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo)
{
	if(signo == SIGINT)
		printf("received SIGINT\n");
}

int main(int argn, char **argv) {
	if(signal(SIGINT, sig_handler) == SIG_ERR)
		printf("\n can't catch SIGINT \n");
	// Wait so that we can easily issue a signal to this process
	while(1)
		sleep(1);
	return 0;
}
