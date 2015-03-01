/* ex5-pointer.c-- Try the pointer rather than the array
   AUTHOR:Ruikang Dai
   DATE:Sun Jan 25 16:44:28 EST 2015
*/
#include <stdio.h>
#include <string.h>

int main(int argn, char **argv) {
	char str[12];
	char *str_ptr;

	strcpy(str,"hello world");

	str_ptr = str;
	// Array name servers as a "static" pointer

	while(*str_ptr) {
		printf("%c has ascii (Hex) value: %x and is stored in mem location %p \n", *str_ptr, *str_ptr, str_ptr);
		str_ptr++;
	}
	return 0;
}
