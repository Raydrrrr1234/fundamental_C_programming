/* opEx6.c--
   AUTHOR:Ruikang Dai
   DATE:Sat Feb  7 11:47:41 EST 2015
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argn, char **argv) {
	char ch, file_name[25];
	FILE *fp;

	strcpy(file_name,argv[1]);
	fp=fopen(file_name,"r"); // read mode

	if(fp == NULL)
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	printf("The contents of %s file are :\n", file_name);
	while((ch = fgetc(fp)) != EOF)
		printf("%c",ch);
	fclose(fp);
	return 0;
}
