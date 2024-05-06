#include "Arithmetic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Return-type (*<fptr-name>) (<param1type>, <param2type>..)



int main(int argc, char *argv[])
{
	if(argc!=4)
	{
		printf("\n Usage %s"
		      "\n -add <num1> <num2> "
		      "\n -subtract <num1> <num2> "
		      "\n -multiply <num1> <num2> "
		      "\n -divide <num1> <num2> \n",argv[0]);
		      
		return -1;
	
	}
	float (*fnPtr) (float, float);
	fnPtr = NULL;	
		
	float val1 = atof(argv[2]), val2 = atof(argv[3]);
	if(!strcmp(argv[1],"-add"))
	{	
		fnPtr = &add;	
	}
	else if(!strcmp(argv[1],"-subtract"))
	{	
		fnPtr = &subtract;	
	}
	else if(!strcmp(argv[1],"-multiply"))
	{	
		fnPtr = &multiply;	
	}
	else if(!strcmp(argv[1],"-divide"))
	{	
		fnPtr = &divide;	
	}
	
	if(fnPtr!=NULL)
	{
		printf("\n The result is = %.2f \n",fnPtr(val1, val2));
		return 1;
	}
	
}
