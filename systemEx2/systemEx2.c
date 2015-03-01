/* systemEx2.c--
   AUTHOR:Ruikang Dai
   DATE:Tue Feb 24 12:55:49 EST 2015
*/
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

char * get_timestamp()
{
	time_t now = time(NULL);
	return asctime(localtime(&now));
}

int main(int argn, char **argv) {
	// Output file will contain the timestamp.
	char * filename = argv[1];
	// Get the current timestamp.
	char * timestamp = get_timestamp();
	// Open the file for writing. If it exists, append to it;
	// Otherwise, create a new file.
	int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
	// Compute the length of the timestamp string.
	size_t length = strlen(timestamp);
	// Write the timestamp to the file.
	write(fd, timestamp, length);
	// All done.
	close(fd);
	return 0;
}
