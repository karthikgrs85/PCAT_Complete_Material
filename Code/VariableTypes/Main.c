#include <stdio.h>
#include "Increment.h"
#include <stdlib.h>
#include <string.h>

#define ARR_MAX 20
#define TEMP_MAX 6
extern int incrVal;//extern to refer to incrVal declared outside this file globally in Increment.c

int var = 10;


int main()
{
	int var1 = 11, var = 12;//Global var hidden here
	int  i, arr[ARR_MAX];
	char buf[TEMP_MAX];
	
	printf("\n Local variables: var1 = %d, var = %d",var1, var);
	{
		extern int var; //Global var visible here
		printf("\n Global var = %d\n",var);
	
	
	}
	printf("\n Enter some integers to an array (max value = %d, press stop to stop) : \n", ARR_MAX);
	do
	{
		fgets(buf, TEMP_MAX, stdin);
		buf[strlen(buf)-1]='\0';
		if(!strcmp(buf, "stop"))
			break;
		arr[i++] = atoi(buf);
	
	}while(1);
	register int size = i;//register used to store size in a local register to make code run faster
	printf("\n Original Array :\n");
	printArray(arr, size);
	
	incrementAllElements(arr,size);
	printf("\n After incrmenting all elements by %d \n",incrVal);
	printArray(arr, size);
	
	printf("\n Enter the increment value :");
	scanf("%d",&incrVal);
	incrementAllElements(arr,size);
	printf("\n After incrmenting all elements by %d \n",incrVal);
	printArray(arr, size);
}

