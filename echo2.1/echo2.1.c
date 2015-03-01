/* echo2.1.c--
   AUTHOR:Ruikang Dai
   DATE:Sat Feb 28 23:36:34 EST 2015
*/
#include <stdio.h>

/* echo command-line arguments; 2nd version */
int main(int argn, char **argv) {
	while(--argn > 0)
		printf("%s%s", *++argv, (argn > 1) ? " " : "");
	printf("\n");
	return 0;
}
