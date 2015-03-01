/* ex4-string-pointer.c--A programe to explorer string and pointers
   AUTHOR:Ruikang Dai
   DATE:Sun Jan 25 16:17:11 EST 2015
*/
#include <stdio.h>
#include <string.h>

int main(int argn, char **argv) {
	char str[12];
	//The string container
	
	strcpy(str,"hello world");
	//Copy "hello world" to str pointer

	for(int i = 0; str[i] != '\0'; i++) {
		printf("%c is stored in memory location %p \n",str[i], &str[i]);
	}
	char c;
	printf("Do you want to print something crazy?(Type y print around str[-10] to str[20])");
	c = getchar();
	if(c == 'y')
		for(int i = -10; i < 20; i++) {
		printf("%2x is stored in memory location %p \n",*(str+i),str+i);
	}
	return 0;
}
