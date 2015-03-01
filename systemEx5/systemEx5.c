/* systemEx5.c--
   AUTHOR:Ruikang Dai
   DATE:Tue Feb 24 20:52:15 EST 2015
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argn, char **argv) {
	int source, dest, n;
	char buf;
	int filesize, i;
	
	if(argn != 3){
		fprintf(stderr, "usage %s <source> <dest>", argv[0]);
		exit(-1);
	}
	
	if((source = open(argv[1], 0400)) < 0) {
	// read permission for user on source
		fprintf(stderr,"can't open source");
		exit(-1);
	}
	
	if((dest = creat(argv[2], 0700)) < 0 ) {
	// rwx permission for user on dest
		fprintf(stderr, "can't create dest");
		exit(-1);
	}

	filesize = lseek(source, (off_t)0, SEEK_END);
	// filesize is lastby + offset

	printf("Source file size is %d\n", filesize);

	for(i = filesize - 1; i >= 0; i--) {
		// read byte by byte from end
		lseek(source, (off_t)i, SEEK_SET);

		n = read(source, &buf, 1);

		if(n != 1) {
			fprintf(stderr, "can't read 1 byte");
			exit(-1);
		}
		
		n = write(dest, &buf, 1);
		if(n != 1) {
			fprintf(stderr, "can't write 1 byte");
			exit(-1);
		}
	}
	write(STDOUT_FILENO, "DONE\n", 5);
	close(source);
	close(dest);
	
	return 0;
}
