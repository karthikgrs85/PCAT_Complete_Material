/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

#define NAME_LEN 50

int main()
{
    float fVal;
    char ch, name[NAME_LEN];
    long int lVal;
    int iVal;
    short int siVal;
    int num;
    void (*ptr) = NULL;
    
    printf("\n Enter a small integer :");
    scanf("%hd",&siVal);
    
    ptr = &siVal;
    iVal = siVal;
    printf("\n iVal = %d, siVal = %hd", *(int*)(ptr), siVal);
    
    
    //Input a moderately large value into iVal
    printf("\n Enter a moderately large integer :");
    scanf("%d",&iVal);
    
    ptr = &iVal;
    siVal = iVal;
    printf("\n iVal = %d, siVal = %hd", *(int*)(ptr), siVal);
    
    printf("\n Enter a relatively large integer :");
    scanf("%ld",&lVal);
    
    ptr = &lVal;
    iVal = lVal;
    printf("\n lVal = %ld, iVal = %d", *(long int*)(ptr), iVal);
    
    //Write code for flushing \n in input console
    
    printf("\n Enter a character :");
    scanf("%c",&ch);
    ptr = &ch;
    
    printf("\n ch = %c ",*(char*)ptr);
    
    printf("\n Enter some float :");
    scanf("%f",&fVal);
    ptr = &fVal;
    
    printf("The entered float in 2 point precision is : %.2f", *(float*)(ptr));
    
    printf("\n Enter your name :");
    scanf("%s",(char *)&name);
    
    ptr = &name;
    printf("Hello World %s", (char*)(ptr));
    
    return 0;
}
