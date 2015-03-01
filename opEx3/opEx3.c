/* opEx3.c--
   AUTHOR:Ruikang Dai
   DATE:Wed Feb  4 21:56:14 EST 2015
*/
#include <stdio.h>
#include <string.h>

int main(int argn, char **argv) {
	char buff[15];
	int pass = 0;
	
	printf("Enter the password:\n");
	gets(buff);
	
	if(strcmp(buff,"ISA_563"))
	{
		printf("Wrong Password\n");
	}
	else
	{
		printf("Correct Password\n");
		pass = 1;
	}
	if(pass)
	{
		printf("Root privileges given to the user\n");
	}
	return 0;
}
