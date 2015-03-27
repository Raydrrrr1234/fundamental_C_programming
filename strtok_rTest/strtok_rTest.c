/* strtok_rTest.c--
   AUTHOR:Ruikang Dai
   DATE:Tue Mar 17 21:51:24 EDT 2015
*/
#include <stdio.h>
// These are optional header files
//#include <errno.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <sys/wait.h>
#include <string.h>
//#include <signal.h>
int main(int argn, char **argv) {

	// Check number of command-line arguments
	if(argn != 2) {

	}
	char *last;
	char *a = strtok_r("command"," \t",&last);
	if (a != NULL)
		printf("%s", a);
	else
		printf("A is null");
	return 0;
}
