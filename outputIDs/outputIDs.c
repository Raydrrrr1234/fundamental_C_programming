/* outputIDs.c--
   AUTHOR:Ruikang Dai
   DATE:Sat Mar 14 14:08:40 EDT 2015
*/
#include <stdio.h>
#include <unistd.h>

int main(int argn, char **argv) {
	printf("My real user ID is	%5ld\n", (long)getuid());
	printf("My effective user ID is	%5ld\n", (long)geteuid());
	printf("My real group ID is 	%5ld\n", (long)getgid());
	printf("My effective group ID is %5ld\n",(long)getegid());
	return 0;
}
