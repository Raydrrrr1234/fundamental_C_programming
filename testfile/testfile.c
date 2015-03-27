/* testfile.c--
   AUTHOR:Ruikang Dai
   DATE:Thu Mar 26 23:31:51 EDT 2015
*/
#include <stdio.h>
// These are optional header files
//#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/wait.h>
#include <string.h>
//#include <signal.h>
#include <fcntl.h>
int main(int argn, char **argv) {

	// Check number of command-line arguments
	if(argn != 2) {

	}
	const char *hi = "This is a test";
	close(STDOUT_FILENO);
	int fd = open("/dev/tty", O_RDWR);
	write(fd,hi,strlen(hi));
	close(fd);
	return 0;
}
