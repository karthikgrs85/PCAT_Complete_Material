#include "Fibonacci.h"
#include <stdio.h>


void printArray(unsigned long long int arr[], int size)
{
	int i;
	for(i =0;i<size-1;++i)
		printf(" %llu, ",arr[i]);
	printf(" %llu ",arr[i]);

}

unsigned long long int getFibonacci(int n)
{
	if(n<1)
		return 0;
	if(n==1||n==2)
		return 1;
	
	return getFibonacci(n-1)+getFibonacci(n-2);

}
void getFibonacciSeries(unsigned long long int arr[], int n)
{
	if(n>MAX_NUM||n<1)
		return;
	for(int i = 1; i<=n;i++)
	{
		arr[i-1]= (((i==1)||(i==2)) ? 1 :arr[i-3]+arr[i-2]);
	}


}

void printFibonacciSeriesRecursive(int n)
{
	
	if(n<1)
	{
		printf("\n n = %d not valid ",n);
		return;
	}
	else if(n>40)
	{
		printf("\n Value of n = %d too high for recursive!.. \n",n);
		return;
	} 
	printf("\n Fibonacci series upto %d (Using Recursive call) :\n",n);
	for(int i = 1; i<=n;i++)
	{
		printf(" %llu ",getFibonacci(i));
	
	
	}

	printf("\n");
}

void printFibonacciSeriesNonRecursive(int n)
{
	if(n<1)
	{
		printf("\n n = %d not valid ",n);
		return;
	}
	
	long long unsigned int arr[MAX_NUM];
	getFibonacciSeries(arr, n);
	printf("\n Fibonacci series upto %d (Using Non-Recursive call) :\n",n);
	
	printArray(arr, n);
	printf("\n");	
	

}
