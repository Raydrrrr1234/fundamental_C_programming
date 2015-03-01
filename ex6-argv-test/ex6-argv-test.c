/* ex6-argv-test.c--This is a test program to figure out what the argv and argn in the main function.
   AUTHOR:Ruikang Dai
   DATE:Sun Jan 25 16:49:20 EST 2015
*/
#include <stdio.h>

int main(int argn, char **argv) {
	int count;
	
	printf("This program was called with \"%s\".\n",argv[0]);
	
	if(argn > 1) {
		for(count = 1; count < argn; count++) {
			printf("argv[%d] = %s\n", count, argv[count]);
		}
	}
	else
		printf("The command had no other arguments.\n");
	return 0;
}
