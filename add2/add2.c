/* add2.c--Add two numbers and print them out together with their sum
   AUTHOR:Ruikang Dai
   DATE:Sun Jan 25 14:51:42 EST 2015
*/
#include <stdio.h>

int main(int argn, char **argv) {
	int first,second;
	
	printf("Enter two integers> ");
	scanf("%d %d", &first, &second);
	printf("The two numbers are: %d %d\n", first, second);
	printf("Their sum is %d\n", first + second);
	return 0;
}
