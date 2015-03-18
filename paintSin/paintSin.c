/* paintSin.c--
	A program to have fun.
	Print the sin graph on the terminal.
   AUTHOR:Ruikang Dai
   DATE:Mon Mar 16 09:48:51 EDT 2015
*/
#include <stdio.h>
// These are optional header files
//#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/wait.h>
//#include <string.h>
//#include <signal.h>
#define INTERVALS 50
#define PI 3.14159265
int main(int argn, char **argv) {

	// Check number of command-line arguments
	if(argn != 3) {
		perror("Usage: paintSin hight width");
		return 1;
	}
	int lines = atoi(argv[1]);
	for (int j = 0; j <= lines; j++) {
		double f = 0;
		for (int i = 0; i < 2*INTERVALS; i++) {
			double r = sin(f*PI);
			if ((double)(lines/2-j)/(double)(lines/2) - r < 0.02 &&
				(double)(lines/2-j)/(double)(lines/2) - r > -0.02)
				printf("*");
			else
				printf(" ");
			f+=1.0/INTERVALS;
		}
		printf("\n");
	}
	return 0;
}
