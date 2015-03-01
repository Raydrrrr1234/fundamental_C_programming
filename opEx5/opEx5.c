/* opEx5.c--
   AUTHOR:Ruikang Dai
   DATE:Sat Feb  7 11:35:22 EST 2015
*/
#include <stdio.h>
#define MAX 100
int getMaxElement(int []);
int size;

int main(int argn, char **argv) {
	int arr[MAX],max,i;

	printf("Integer array size:");
	scanf("%d", &size);

	for(i = 0; i < size; i++) {
		printf("Enter integer #%d:",i);
		scanf("%d",&arr[i]);
	}

	max = getMaxElement(arr);
	printf("The largest integer entered: %d\n",max);
	return 0;
}
int getMaxElement(int arr[]) {
	static int i = 0, max = -9999;

	if(i < size){
		if(max < arr[i])
			max=arr[i];
		i++;
		getMaxElement(arr);
	}
	return max;
}
