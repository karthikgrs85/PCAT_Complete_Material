// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_LEN 80
#define MAX_OPER 4
#define MAX_LEN 80
#define PI 3.14159
#define AREA(r) PI*(r)*(r)
//Calling AREA(r+2) Without brace-> PI*r+2*r+2 = 3.14*2+2*2+2 = 6.28+6
//Calling AREA(r+2) With brace -> PI*4*4 ~ 50
#define GETNAME(x) #x
#define HELLOWORLD(x) GETNAME(Hello x)
#define JOINTWOWORDS(x,y)  x##y
#define GETFULLNAME(x,y) GETNAME(JOINTWOWORDS(JOINTWOWORDS(x, ),y)) 


char oper[] = {'*','/', '+', '-'};

float getArea(float r)
{
    return PI*r*r;
}
int strLen(const char*)
{
    
}
void calculate(const char *expression)
{
    char *operPos = NULL;
    char operVal;
    float x, y, result = 0;
    int idx = 0;
    while(operPos==NULL && idx < MAX_OPER)
    {
        operVal = oper[idx++];
        operPos = strchr(expression,operVal);

    }
    if(operPos)
    {
        
        x = atof(expression);
        y = atof(operPos+1);
        switch(operVal)
        {
            case '+':
                result = x+y;
                break;
            case '-':
                result = x-y;
                break;
            case '*':
                result = x*y;
                break;
            case '/':
                result = x/y;
                break;
            default:
                printf("\n Operation Undefined!");
                return;
        }
        //printf("\n The result of the expression is %.3f", result);
        
        return;
    }
    printf("\n No Valid operator found!");
    return;
}


int main() {
    // Write C code here
    char expression[MAX_LEN];
    int a = 23, b = 44;
    float r =2.0;
    char buf[BUF_LEN] = GETNAME(Hello World);
    printf("Testing Stringization Macro buf = %s \n",buf);
    
    printf("\n Testing HelloWorld Stringization macro : %s\n",HELLOWORLD(Jack));
    
    printf("\n Enter radius of a circle :");
    scanf("%f",&r);
    printf("\n The area of the circle with r = %.2f is = %.2f\n",r, AREA(r));
    
    printf("\n The area of the circle with r+2 is = %.2f\n",AREA(r+2));
    
    
    //printf("\n Enter a mathematical expression :\n");
    //scanf("%s",&expression);
    //calculate(expression);
    /*printf("%.3f",AREA(r+2));*/
    printf("\n Testing Concatenation macro : %d",JOINTWOWORDS(23,44));
    
    
    printf("\n Testing Concatenation macro :" HELLOWORLD(Krishna));
    //PI*r+2*r+2
    //3.14*2+2*2+2
    return 0;
}