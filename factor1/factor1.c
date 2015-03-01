/* factor1.c--Prompt the user to enter an integer N. Print out ifN prime or not. If not, print out all of N's proper factors.
   AUTHOR:Ruikang Dai
   DATE:Sun Jan 25 16:01:05 EST 2015
*/
#include <stdio.h>

int main(int argn, char **argv) {
	int n, lcv, flag;
	//flag initially 1 and becomes 0 if we determine that n is not a prime
	printf("Enter value of N > ");
	scanf("%d",&n);
	for(lcv=2,flag=1; lcv<=(n/2); lcv++) {
		if((n%lcv)==0) {
			if(flag)
				printf("The non-trivial factors of %d are:\n",n);
			flag = 0;
			printf("\t%d\n",lcv);
		}
	}
	if(flag)
		printf("%d is prime\n",n);
	return 0;
}
