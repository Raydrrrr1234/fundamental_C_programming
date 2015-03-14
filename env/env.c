/* env.c--
	A program to test environ defined by Unix System
   AUTHOR:Ruikang Dai
   DATE:Sat Mar 14 13:17:59 EDT 2015
*/
#include <stdio.h>

extern char **environ;

int main(int argn, char **argv) {
	int i;
	
	printf("The environment list follows: \n");
	for (i = 0; environ[i] != NULL; i++)
		printf("environ[%d]: %s\n", i, environ[i]);
	return 0;
}
