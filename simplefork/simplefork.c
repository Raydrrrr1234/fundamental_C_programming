/* simplefork.c--
	In the following program, both parent and child execute the x=1 assignment statement after running from fork.
   AUTHOR:Ruikang Dai
   DATE:Sat Mar 14 15:07:15 EDT 2015
*/
#include <stdio.h>
#include <unistd.h>
int main(int argn, char **argv) {
	int x;

	x = 0;
	fork();
	x = 1;
	printf("I am process %ld and my x is %d\n", (long)getpid(), x);
	return 0;
}
