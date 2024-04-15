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
typedef char[BUF_LEN] buffer;



int main()
{
  //  buffer name;
    number i;
    decimal_number dec1;
    buffer name;
    
    printf("\n Enter your name :");
    scanf("%s",&name);
    
    printf("\n Enter a number :");
    scanf("%d",&i);
    printf("\n Enter a decimal number :");
    scanf("%f",&dec1);
    printf("\n Hello World %s, %d, %.2f", name, i, dec1);
    
    
    
}
