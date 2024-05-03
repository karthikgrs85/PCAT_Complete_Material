#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Fibonacci.h"

long long unsigned int factorial(int n)
{
	
	if(n==1)
		return 1;
	return n*(factorial(n-1));
		


}


//We call the program like this -> <program-name> -factorial <n>
// Or <program-name> -fibonacci <n>
int main(int argc, char *argv[])
{
	if(argc!=3)
	{
		printf("\n Usage : %s  \n"
			"          -Factorial <n> \n"
			"          -FibonacciRecursive <n> \n"
			"          -FibonacciNonRecursive <n> \n", argv[0]);
		return -1;	
	
	}
	
	int num = atoi(argv[2]);
	if(!strcmp(argv[1],"-Factorial"))
	{
		printf("\n The factorial of %d = %llu ",num, factorial(num));
	
	}
	else if(!strcmp(argv[1],"-FibonacciRecursive"))
	{
		
		printFibonacciSeriesRecursive(num);
	
	}
	else if(!strcmp(argv[1],"-FibonacciNonRecursive"))
	{
		
		printFibonacciSeriesNonRecursive(num);
	
	}
	else
	{
		printf("\n Not a valid argument \n");
	
	}
	return 1;

}
