/* envVar2.c--
   AUTHOR:Ruikang Dai
   DATE:Tue Feb 10 21:04:40 EST 2015
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argn, char **argv) {
	char *ptr, *getenv();

	if((ptr = getenv("HOME"))==(char *)0)
		printf("HOME is not defined\n");
	else
		printf("HOME=%s\n", ptr);

	return 0;
}
