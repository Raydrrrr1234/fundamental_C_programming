/* outputIDs.c--
	Output current process IDs
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
	printf("My parent ID is		%5ld\n", (long)getppid());
	printf("My current ID is 	%5ld\n", (long)getpid());
	return 0;
}
