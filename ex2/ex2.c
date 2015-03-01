/*  ex2.c -- Pointers and arrays programming
    AUTHOR: Ruikang Dai
    DATA: Jan.25.15
*/
#include <stdio.h>

int main(int argn, char **args)
{
    char ch = 'c';
    char *chptr = &ch;  //Set the value of pointer variable chptr
                        //to the ADDRESS of char variable ch
    
    int i = 20;
    int *intptr= &i;    //Set the value of pointer variable intptr
                        //to the ADDRESS of char variable i

    float f = 1.20000;
    float *fptr = &f;
    char *ptr = "Hello World"; 
                        //Initialize ptr to the starting address of static
                        //character string "Hello World". Note:In C language
                        //character strings end with a NULL byte(ascii 0).
    printf("\n %c, %d, %f, %c, %s\n", *chptr, *intptr, *fptr, *ptr, ptr);
    return 0;
}
