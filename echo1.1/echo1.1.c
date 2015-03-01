/* echo1.1.c--
   AUTHOR:Ruikang Dai
   DATE:Sat Feb 28 23:33:37 EST 2015
*/
#include <stdio.h>
/* echo command-line arguments; 1st Version */

int main(int argn, char **argv) {
	int i;
	
	for(i = 1; i < argn; i++)
		printf("%s%s", argv[i], (i < argn-1) ? " " : "");
	printf("\n");
	return 0;
}
