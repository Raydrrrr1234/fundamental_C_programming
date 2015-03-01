/* ex3.c-- This is an programe of pointers and string arrays
   AUTHOR:Ruikang Dai
   DATE:Sun Jan 25 13:58:00 EST 2015
*/
#include <stdio.h>

struct st{
int a;
char ch;
};

int main(int argn, char **argv) {
	struct st obj;
	struct st *stobj = &obj;

	stobj->a = 5;
	stobj->ch = 'C';

	printf("\n obj.a == %d   obj.ch == %c \n", obj.a,obj.ch);
	printf("\n stobj->a == %d stobj->ch == %c \n", stobj->a,stobj->ch);
	return 0;
}
