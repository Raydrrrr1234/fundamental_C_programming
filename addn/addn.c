/* addn.c--
   AUTHOR:Ruikang Dai
   DATE:Sun Jan 25 15:46:14 EST 2015
*/
#include <stdio.h>

int main(int argn, char **argv) {
	int n;		// The number of numbers to be read
	int sum;	// The sum of numbers already read
	int current;	// The number just read
	int lcv;	// Loop control variable, it counts the number of numbers already read
	printf("Enter a positive number n> ");
	scanf("%d",&n);
	sum=0;
	for(lcv=0; lcv<n; lcv++) {
		printf("\nEnter integer %d> ",lcv+1);
		scanf("%d",&current);
		sum=sum+current;
	}
	printf("The sum is %d\n",sum);
	return 0;
}
