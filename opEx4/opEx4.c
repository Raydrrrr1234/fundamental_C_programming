/* opEx4.c--
   AUTHOR:Ruikang Dai
   DATE:Wed Feb  4 22:06:48 EST 2015
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argn, char **argv) {
	char name[100];
	char *description;

	strcpy(name,"Ruikang Dai");

	/* allocate memory dynamically */
	description = malloc(200*(sizeof(char)));
	if(description == NULL)
	{
		fprintf(stderr,  "Error - unable to allocate required memory\n");
	}
	else
	{
		strcpy(description,"ISA 563:Fundamentals of Systems Programming");
	}
	printf("Name = %s\n",name);
	printf("Description: %s\n", description);
	return 0;
}
