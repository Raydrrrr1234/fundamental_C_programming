/* systemEx1.c--
   AUTHOR:Ruikang Dai
   DATE:Tue Feb 24 12:34:13 EST 2015
*/
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argn, char **argv) {
	unsigned char buffer[16];
	int offset = 0;
	int bytes_read;
	int i;

	// Open the file for reading. 
	int fd = open(argv[1], O_RDONLY);
	// Read from the file, one chunk at a time. Continue until read"comes up short", that is, reads less than we asked for. This indicates that we've hit the end of the file.
	do {
	// Read the next line's worth of bytes.
		bytes_read = read(fd, buffer, sizeof(buffer));
	// Print the offset in the file, followed by the bytes themselves.
		printf("0x%06x:", offset);
		for(i = 0; i < bytes_read; ++i)
			printf("%02x", buffer[i]);
		printf("\n");
	// Keep count of our position in the file.
		offset += bytes_read;
	} while(bytes_read == sizeof(buffer));
	// All done
	close(fd);
	return 0;
}
