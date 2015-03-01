/* DynamicMemoryAllocation.c--
   AUTHOR:Ruikang Dai
   DATE:Tue Feb 10 20:54:14 EST 2015
*/
#include <stdio.h>
#include <stdlib.h>

struct name{
	int a;
	char c[30];
};

int main(int argn, char **argv) {
	struct name *ptr;
	int i,n;
	printf("Enter n:");
	scanf("%d",&n);
	
	ptr=(struct name*)malloc(n*sizeof(struct name));
	for(i=0;i<n;i++){
		printf("Enter string and integer respectively:\n");
		scanf("%s%d",(char*) &(ptr+i)->c,&(ptr+i)->a);
	}
	printf("Displaying Information:\n");
	for(i=0;i<n;i++)
		printf("%s\t%d\t\n",(ptr+i)->c,(ptr+i)->a);
	return 0;
}
