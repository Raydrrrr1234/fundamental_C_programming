/* words-count.c--Test for words count. Pipe input.
   AUTHOR:Ruikang Dai
   DATE:Mon Jan 26 19:15:55 EST 2015
*/
#include <stdio.h>
#define IN 1 	/*inside a word*/
#define OUT 0	/*outside a word*/

/* count lines, words, and characters in input */

int main(int argn, char **argv) {
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while((c = getchar()) != EOF) {
		++nc;
		if(c == '\n')
			++nl;
		if(c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if(state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
	return 0;
}
