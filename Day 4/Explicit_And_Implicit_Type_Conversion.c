/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

#define BUF_LEN 1024

typedef int number;
typedef float decimal_number;
//typedef char[BUF_LEN] buffer;



int main()
{
  //  buffer name;
    number x, y, z, avg_num, result_num;
    decimal_number dec1, avg_dec, pi= 3.1459, result_dec;
   
    printf("\n Enter 3 numbers :");
    scanf("%d %d %d ",&x, &y, &z);
    printf("\n Enter a decimal number :");
    scanf("%f",&dec1);
	
	//Implicit type conversion
    avg_num = ((x+y+z)/2+dec1);
    avg_dec = ((x+y+z)/2+dec1);
    
    printf("\n Hello World  avg_num = %d, avg_dec = %.3f", avg_num, avg_dec);
    
	//Explicit type conversion
    avg_dec = ((x+y+z)/2+(int)dec1);
    printf("\n Hello World  avg_num = %d, avg_dec = %.3f", avg_num, avg_dec);

    
    
}
