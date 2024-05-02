#include "PrintBits.h"
#include <math.h>
#include <stdio.h>

void printAllBitsOfNum(signed int num)

{


 int power = 31;
 printf("\n");
 for(; power>=0 ; power--)

 {

   //Bitwise & returns true if the operand bit is set

   //If bit index pow(2, power) is set it returns true

   if(num&((int)pow(2,power)))

   {

     printf("1");

   }

   else

   {

     printf("0");

   }

    

 }
 printf("\n");

}


void printAllBitsOfChar(signed char ch)

{

 int power = 8;
 printf("\n");
 for(; power>=0 ; power--)

 {

   //Bitwise & returns true if the operand bit is set

   //If bit index pow(2, power) is set it returns true

   if(ch&((int)pow(2,power)))

   {

     printf("1");

   }

   else

   {

     printf("0");

   }

    

 }
 printf("\n");


}

