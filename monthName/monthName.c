/* monthName.c--
   AUTHOR:Ruikang Dai
   DATE:Tue Feb 10 20:25:54 EST 2015
*/
#include <stdio.h>
char *month_name(int n);
int main(int argn, char **argv) {
	for(int i = 0; i < 12; i++)
		printf("%s",month_name(i));
	return 0;
}

char *month_name(int n)
{
	static char *name[] = {
	"Illegal month",
	"January", "February"
	"March","April","May",
	"June","July","August",
	"September","October","November",
	"December"
	};
	
	return (n < 1 || n > 12) ? name[0] : name[n];
}
