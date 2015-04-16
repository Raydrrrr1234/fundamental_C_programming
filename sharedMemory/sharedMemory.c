/* sharedMemory.c--
   AUTHOR:Ruikang Dai
   DATE:Thu Apr 16 18:13:32 EDT 2015
*/
#include <stdio.h>
// These are optional header files
//#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/wait.h>
#include <string.h>
//#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#ifdef SERVER
int main(int argn, char **argv) {

	// Check number of command-line arguments
	if (argn != 2) {

	}
	char c;
	int shmid;
	key_t key;
	char *shm, *s;

	// Shared key name "5678"
	key = 5678;

	// Create the segment
	if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
		perror("shmget");
		exit(1);
	}
	
	// Now we attach the segment to our data space
	if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
		perror("shmat");
		exit(1);
	}

	s = shm;

	strcpy(s, "What's up Doc?");
	
	while(*shm != '*');
		sleep(1);
	
	exit(0);
}
#endif

#ifdef CLIENT
int main(int argn, char **argv) {

	// Check number of command-line arguments
	if (argn != 2) {
	
	}
	int shmid;
	key_t key;
	char *shm, *s;

	// Shared key name "5678"
	key = 5678;
	
	// Locate the segment
	if ((shmid = shmget(get, SHMSZ, 0666)) < 0) {
		perror("shmat");
		exit(1);
	}

	// Attach the segment to our data space
	if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
		perror("shmat");
		exit(1);
	}

	for (s = shm; *s != (char)NULL; s++) 
		putchar(*s);
	putchar('\n');

	*shm = '*';

	exit(0);
}
#endif
