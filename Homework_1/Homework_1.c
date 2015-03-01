/* Homework_1.c--
	1.Insertion sort all input variables to decreasing order.
	2.Print out the largest value entered.
	3.Print out the smallest value entered.
	4.Include error checking to catch values other than positive integers
	5.Implement the int findMax(int first,int second) function
   AUTHOR:Ruikang Dai
   DATE:Sun Jan 25 17:00:52 EST 2015
*/

#define ZERO 0			// The marco for 0 number
#define BUFFER_SIZE 256		// The buffer of input size
#define INTEGER_MAX 2147483647
#define INTEGER_MIN -2147483648
#define MAX_NUMBER 20
#define MIN_NUMBER 1
#include <stdio.h>
#include <stdlib.h>		// Dynamic memory allocation header
#include <stdbool.h>

// Receives: 2 incoming integers
// Returns the larger one
int findMax(int first,int second);
// Implementation of insertion sort
// Receive: int *i_array; (the pointer point to the array that is going to sort)
// Receive: int n; (the size of the array)
// No return, array will be sorted internal
void insertion_sort(int *i_array, int n);

// This function receive no parameter
// Return the input integer that is legal
int integer_input() {
	//A double to temporarily store input to prevent overflow
	double temp;
	//The buffer for input(in case of char input)
	char buffer[BUFFER_SIZE];
	//The flag for character check(false: input contains char, otherwise true
	bool flag = false;
	//Infinitive check whether the input is string
	while (!flag) {
		//Clean the error input flow
		fflush(stdin);
		scanf("%s",buffer);
		//Check each character of input falls between 0-9
		for(int i = 0; buffer[i] != '\0'; i++)
		{
			if(buffer[i] < '0' || buffer[i] > '9') {
				flag = false;
				printf("There is a character in the input.\nHope you are not tricking me with a hex number.\nPlease retry again>");
				break;
			}
			else
				flag = true;	
		}
		//If there is a character, no need to check overflow
		if(flag == false)
			continue;
		//Translate a string to a double value
		temp = strtod(buffer,NULL);
		//Overflow check
		if(temp > INTEGER_MAX || temp < INTEGER_MIN) {
			printf("Overflow error: %.0lf is an illegal number. Please retry.>",temp);
			flag = false;
		}
	}
	return (int)temp;
}

int main(int argn, char **argv) {
	int n;		//The number of numbers to be read
	//The integer pointer to an array that dynamic defined in heap
	int *i_array;	
	//Welcom words with RED COLOR
	printf("\x1B[31m" "Student name:Ruikang dai\tHomework#1\nDynamic memory allocation with malloc standard function\n");
	printf("\033[0m" "Enter how many number will be entered> ");
	//Use a universal method to get a correct input
	n = integer_input();
	while(n > MAX_NUMBER || n < MIN_NUMBER) {
		printf("Enter how many number will be entered> ");
		n = integer_input();
	}
	// Dynamic allocate memory from heap
	i_array = (int *)malloc(sizeof(int)*n);
	// Read n input numbers
	for(int i = 0; i < n; i++) {
		printf("Enter number %d>", i+1);
		i_array[i] = integer_input();
		// Infinitive error check until user type the right number
		while(i_array[i] < ZERO) {
			printf("Error: %d is an illegal entry. Please retry.",i_array[i]);
			printf("Enter number %d>", i+1);
			i_array[i] = integer_input();
		}
	}

	// Sort the array (Algorithm: insertion sort)
	insertion_sort(i_array,n);
	// Output
	printf("The result is:");
	for(int i = 0; i < n; i++)
		printf(" %d",i_array[i]); 
	printf("\nMax value: %d",i_array[0]);
	printf("\nMin value: %d",i_array[n-1]);
	printf("\n\n");
	free(i_array);
	return 0;
}
// The findMax function implementation
// The only place I used this function is in the while loop of insetion_sort Algorithm
int findMax(int first, int second) {
	if(first > second)
		return first;
	return second;
}
// The insertion_sort algorithm implementation
void insertion_sort(int *i_array, int n) {
	int key;	// The temprary integer for comparing
	for(int i = 1, j = 0; i < n; i++) {
		key = i_array[i];
		j = i-1;
		// Insert i_array[i] into the sorted sequence i_array[i...j-1], move the space for the new element.
		while(j >= 0 && (findMax(i_array[j], key)==key)) {
			i_array[j+1] = i_array[j];
			j = j-1;
		}
		// Insert the key value to the right position
		i_array[j+1] = key;
	}
}
