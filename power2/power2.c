/* power2.c--Print out powers of 2: 1,2,4,8,...,up
   AUTHOR:Ruikang Dai
   DATE:Sun Jan 25 15:20:35 EST 2015
*/
#include <stdio.h>
#define N 16

int main(int argn, char **argv) {
	int n;		// The current exponent
	int val = 1;	// The current power of 2

	printf("\t n \t 2^n\n");	// \t means a tab
	printf("\t==================\n");
	for(n = 0; n <= N; n++) {
		printf("\t%3d \t %6d\n",n,val);
		val = 2*val;
	}
	return 0;
}
