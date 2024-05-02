// Online C compiler to run C program online

#include <stdio.h>

#include <math.h>

#include <stdbool.h>

#include "PrintBits.h"



//Bitwise operators compares the values of 2 operands bitwise

//nth bit of each operand

// Bitwise AND-> & -> returns bit =1 at nth position only if nth bith of both are set, otherwise nth bit = 0

// Bitwise OR-> | -> returns bit = 0 at nth position only if nth bit of both operands are 0, 1 otherwise

//Bitwise ^ (XOR) -> returns bit = 1 at nth position only if the nth bits of both operands are different, otherwise 0

//Bitwise Left Shift << n -> left shifts the value in binary by n (padding it by 0s)

//Bitwise Right Shift >>n -> right shifts the value in binary by n

//Bitwise NOT ~ ->negates each bit


//Set nth bit..(1,2..n)

//|=(1<<(n-1))


//a = 1100001 , n = 2

// a=(1100001)|(10)

// a =1100011


void setNthBit(unsigned char *a, int n)

{

  (*a)|=(1<<(n-1)); 

}




//Resetting a nth bit, n = 1

// &=~(1<<(n-1))

// a= (1100001)&~(1)

// a =(1100001)&(11111110)

// a = (1100000)

void resetNthBit(unsigned char *a, int n)

{

  (*a)&=~(1<<(n-1)); 

}



//Flip a nth bit, n = 1

//^=(1<<(n-1))

//^=(1<<(1-1))

// a = (1100001)^(1)

// 1100000


void flipNthBit(unsigned char *a, int n)

{

  (*a)^=(1<<(n-1)); 

}


//Test a nth bit, n = 1

// a&(1<<(n-1)

// a&(1<<(1-1))

// =(1100001)&(00001)

//1

//true


//Test the nth bit, n= 3

// = a&(1<<(3-1))

// a&(1<<2)

//= (1100001)&(100)

//0

//false

bool testNthBit(unsigned char a, int n)

{

  return (a&(1<<(n-1)));

   

}





int main() {

  // Write C code here

  printf("Try programiz.pro");

  //Test bitwise operator

  unsigned char ch, result;

  int n;

  printf("\n Enter any character:");

  scanf("%c", &ch);

  result = ch;

	printf("\n Enter any positive integer value n :");

	scanf("%d",&n);

   

  printf("\n The bit representation of %c : \n",ch);

  printAllBitsOfChar(ch);

   

  setNthBit(&result, n);

  printf("\n After setting %d bit, result = %c\n", n, result);

  printAllBitsOfChar(result);

   

  result = ch;

  resetNthBit(&result, n);

  printf("\n After resetting %d bit, result = %c\n", n, result);

  printAllBitsOfChar(result);
   

  result = ch;

  flipNthBit(&result, n);

  printf("\n After flipping %d bit, result = %c\n", n, result);

  printAllBitsOfChar(result); 

	testNthBit(ch, n)?(printf("\n The %d bit in %c is set \n", n, ch)):(printf("\n The %d bit in %c is not set \n", n, ch));

  return 0;

}
