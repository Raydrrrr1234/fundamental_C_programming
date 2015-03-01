/* opEx2.c--
   AUTHOR:Ruikang Dai
   DATE:Wed Feb  4 17:27:12 EST 2015
*/
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#define printsize(x) printf("sizeof("#x")=%lu\n",sizeof(x))
int main(int argn, char **argv) {
	printsize(char);
	printsize(double);
	printsize(int);
	printsize(long);
	printsize(long long);
	printsize(short);
	printsize(void *);

	printf("\n");
	printsize(clock_t);
	printsize(gid_t);
	printsize(pid_t);
	printsize(size_t);
	printsize(ssize_t);
	printsize(time_t);
	printsize(time_t);
	printsize(uid_t);
	return 0;
}
