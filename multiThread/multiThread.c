/* multiThread.c--
   AUTHOR:Ruikang Dai
   DATE:Thu Apr 16 15:04:20 EDT 2015
*/
#include <stdio.h>
// These are optional header files
#include <errno.h>
#include <stdlib.h>
//#include <unistd.h>
//#include <sys/wait.h>
//#include <string.h>
//#include <signal.h>
#include <pthread.h>

void thread_funct_1(int *);
void thread_funct_2(int *);
void do_wrap_up(int, int);

int r1 = 0, r2 = 0;

extern int main(int argn, char **argv) {

	// Check number of command-line arguments
	if (argn != 2) {

	}
	// ids for the first and second thread
	pthread_t thread1, thread2;
	
	// creating the first thread. retval != 0 indicates error
	if (pthread_create(&thread1, NULL, (void *) thread_funct_1, (void *) &r1) != 0)
		perror("pthread_create"), exit(1);
	// Creating the second thread, its argument is passed with a void * 
	// by pthread_creat, the actual function expects an int.
	if (pthread_create(&thread2, NULL, (void *) thread_funct_2, (void *) &r2) != 0)
		perror("pthread_create"), exit(1);
	// Waiting for the first thread to terminate.
	// Thread's return (exit) value gets discarded
	if (pthread_join(thread1, NULL) != 0)
		perror("pthread_join"), exit(1);
	
	// Waiting for the second thread to terminate
	if (pthread_join(thread2, NULL) != 0)
		perror("pthread_join"), exit(1);

//	do_wrap_up(r1, r2);
	return 0;
}


void thread_funct_1(int *pnum_times) {
	int i,j,x;

	for (i = 0; i < 4; i++) {
		printf("in thread_funct_1\n");
		for (j = 0; j < 10000; j++) x = x+i;
		(*pnum_times)++;
	}
}

void thread_funct_2(int *pnum_times) {
	int i,j,x;

	for (i = 0; i < 4; i++) {
		printf("in thread_funct_2 \n");
		for (j = 0; j < 10000; j++) x = x+i;
		(*pnum_times)++;
	}
}
