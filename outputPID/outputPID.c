/* outputPID.c--
   AUTHOR:Ruikang Dai
   DATE:Sat Mar 14 14:06:16 EDT 2015
*/
#include <stdio.h>
#include <unistd.h>

int main(int argn, char **argv) {
	printf("I am process %ld\n", (long)getpid());
	printf("My parent is %ld\n", (long)getppid());
	return 0;
}
