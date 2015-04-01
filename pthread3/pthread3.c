/* pthread3.c--
	This is a program that show how to control the thread in order.
	Using conditional signal, it is similar to the mutex.
	But they are using different methods.
   AUTHOR:Ruikang Dai
   DATE:Tue Mar 31 20:16:08 EDT 2015
*/
#include <stdio.h>
// These are optional header files
//#include <errno.h>
#include <stdlib.h>
//#include <unistd.h>
//#include <sys/wait.h>
//#include <string.h>
//#include <signal.h>
#include <pthread.h>
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;

void *functionCount1();
void *functionCount2();
int count = 0;
#define COUNT_DONE 10
#define COUNT_HALE1 3
#define COUNT_HALE2 6

int main(int argn, char **argv) {

	// Check number of command-line arguments
	if(argn != 2) {

	}
	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL,&functionCount1, NULL);
	pthread_create(&thread2, NULL,&functionCount2, NULL);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Final count: %d\n", count);

	return 0;
}
void *functionCount1() {
	for (;;) {
		pthread_mutex_lock(&count_mutex);

		pthread_cond_wait(&condition_var, &count_mutex);
		count++;
		printf("Counter value functionCount1: %d\n", count);

		pthread_mutex_unlock(&count_mutex);

		if (count >= COUNT_DONE) return (NULL);
	}
}
void *functionCount2() {
	for (;;) {
		pthread_mutex_lock(&count_mutex);

		if (count < COUNT_HALE1 || count > COUNT_HALE2) {
			pthread_cond_signal(&condition_var);
		}
		else {
			count++;
			printf("Counter value functionCount2: %d\n",count);
		}

		pthread_mutex_unlock(&count_mutex);

		if (count >= COUNT_DONE) return (NULL);
	}
}
