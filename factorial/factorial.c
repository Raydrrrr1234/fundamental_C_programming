/* factorial.c--
   AUTHOR:Ruikang Dai
   DATE:Sun Jan 25 15:55:54 EST 2015
*/
#include <stdio.h>
int fact(int n);

int main(int argn, char **argv) {
	int current;
	printf("Enter a positive integer [ to determinate enter non-position] >");
	scanf("%d", &current);

	while(current > 0) {
	printf("The factorial of %d is %d\n", current, fact(current));	
	printf("Enter a positive integer [ to determinate enter non-position] >");
	scanf("%d", &current);
	}
	return 0;
}
int fact(int n) {
	int lcv;
	int p;

	for(p=1,lcv=2; lcv<=n; p=p*lcv,lcv++);
	return p;
}
