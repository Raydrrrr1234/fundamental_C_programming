/* OverviewPart3Ex1.c--
	Prompt the user to enter a set of letters from the keyboard and display them in a descending order. Include error checking for data entry.
   AUTHOR:Ruikang Dai
   DATE:Wed Feb  4 17:11:57 EST 2015
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argn, char **argv) {
	char Array[300], a;
	int i,j;
	int count = 0;
	printf("Enter letters:");
	while((Array[count] = getchar()) != '\n')
	if( ((Array[count] >= 'A') && (Array[count] <= 'Z')) || 
		((Array[count] >= 'a') && (Array[count] <= 'z')) )
		count++;
	else {
		printf("Illegal entry - goodbye\n");
		printf("The entry is %d:'%c'\n",count,Array[count]);
		exit(1);
	}
	Array[count] = '\0';

	printf("%d letters were entered\n", count);
	printf("Original order: %s\n", Array);
	for( i = 0; i < count; i++) {
		for(j = i+1; j < count; j++) {
			if(Array[i] < Array[j]) {
				a = Array[i];
				Array[i] = Array[j];
				Array[j] = a;
			}
		}
	}
	printf("Letters in descending order are given below:\n");

	for(i = 0; i < count; i++) {
		printf("%c has ascii value %x\n", Array[i], Array[i]);
	}
	return 0;
}
