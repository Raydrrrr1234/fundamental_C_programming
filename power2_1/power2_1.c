/* power2_1.c--Print out powers of 2: 1,2,4,8,...,up. And I seperated the marco with a header file.
   AUTHOR:Ruikang Dai
   DATE:Sun Jan 25 15:38:29 EST 2015
*/
#include "power2_1.h"

#include <stdio.h>

int main(int argn, char **argv) {
	int n;          // The current exponent
        int val = 1;    // The current power of 2
 
        printf("\t n \t 2^n\n");        // \t means a tab
        printf("\t==================\n");
        for(n = 0; n <= N; n++) {
                printf("\t%3d \t %6d\n",n,val);
                val = 2*val;
        }
	return 0;
}
