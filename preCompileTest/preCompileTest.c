/* preCompileTest.c--
   AUTHOR:Ruikang Dai
   DATE:Wed Feb 11 12:33:27 EST 2015
*/
#include <stdio.h>
//Error expression of the x
//#define printsize(x) printf("printf("#x")=%lu\t%s\n",sizeof(x),&x)
//Correct with () and parament
//#define printsize(x,abc) printf("printf("#x")=%lu\t%d\n",sizeof(x),abc)
//
#define printsize(x) printf("printf("#x")=%lu\t%d\n",sizeof(x),y)
int main()
{
	int y=1;
	printsize(int);
	return 0;
}
