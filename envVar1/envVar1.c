/* envVar1.c--
   AUTHOR:Ruikang Dai
   DATE:Tue Feb 10 21:01:44 EST 2015
*/
#include <stdio.h>

int main(int argn, char **argv, char **envp) {
	int i;
	for(i = 0; envp[i] != (char *) 0;i++)
		printf("%s\n", envp[i]);
	return 0;
}
