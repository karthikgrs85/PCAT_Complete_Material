#include <stdio.h>
#include "HeapSort.h"
#include "Array.h"
#include <string.h>
#include <stdlib.h>

#define INT_ARR_MAX 30
#define INT_BUF 5

int main()
{
	int arr[INT_ARR_MAX], size = 0;
	char buf[INT_BUF];
	printf("\n Please enter some numbers, stop to exit...:\n");
	do
	{
		fgets(buf, INT_BUF, stdin);
		buf[strlen(buf)]='\0';
		if(!strcmp(buf,"stop"))
			break;
		arr[size++] = atoi(buf);
	
	}while(size<=INT_ARR_MAX);
	
	
	
	printf("\n Before Heap Sort :\n");
	printArray(arr, size);
	
	//bubbleSort(arr, size);
	//insertionSort(arr, size);
	heapSort(arr, size);
	printf("\n After Merge Sort :\n");
	printArray(arr, size);


}
