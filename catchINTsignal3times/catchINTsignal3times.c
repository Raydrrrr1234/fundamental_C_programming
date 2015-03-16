/* catchINTsignal3times.c--
	This is a program that catch Ctrl-c three times and print error info at the terminal.
   AUTHOR:Ruikang Dai
   DATE:Mon Mar 16 09:24:49 EDT 2015
*/
#include <stdio.h>
// These are optional header files
//#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/wait.h>
//#include <string.h>
#include <signal.h>

struct sigaction act;
struct sigaction old_act;

void catchctrlc(int signo);

static int times = 0;

int main(int argn, char **argv) {

	// Check number of command-line arguments
	if(argn != 2) {

	}
	act.sa_handler = catchctrlc;
	act.sa_flags = 0;
	if ((sigemptyset(&act.sa_mask) == -1) ||
		(sigaction(SIGINT, &act, &old_act) == -1))
		perror("Failed to set SIGINT to handle Ctrl-c");

	while(1);
	return 0;
}
void catchctrlc(int signo) {
	char handmsg[] = "\nI found Ctrl-c\n";
	int msglen = sizeof(handmsg);
	write(STDERR_FILENO, handmsg, msglen);
	times++;
	if (times >= 3) {
		if ((sigaction(SIGINT, &old_act, NULL)) == -1) {
			perror("Failed to REVERT SIGINT TO handle Ctrl-c");
			exit(-1);
		}
	}
}
