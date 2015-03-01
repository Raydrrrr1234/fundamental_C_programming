/* Section4.1.c--
	Pattern finding.
	The same function of grep
   AUTHOR:Ruikang Dai
   DATE:Sun Mar  1 13:18:51 EST 2015
*/
#include <stdio.h>
#define MAXLINE 1000 // maximum input line length

int iGetline(char line[], int lim);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(int argn, char **argv) {
	char line[MAXLINE];
	int found = 0;
	while(iGetline(line, MAXLINE) > 0) {
		if(strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	}
	return found;
}

// getline: getline into s, return length
int iGetline(char s[], int lim) {
	int c, i;
	i = 0;
	while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

// strindex: return index of t in s, -1 if none
int strindex(char s[], char t[]) {
	int i,j,k;
	
	for(i = 0; s[i] != '\0'; i++) {
		for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
		if(k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}
