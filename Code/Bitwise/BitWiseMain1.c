// Online C compiler to run C program online

#include <stdio.h>

#include <math.h>
#include "PrintBits.h"



//Bitwise operators compares the values of 2 operands bitwise

//nth bit of each operand

// Bitwise AND-> & -> returns bit =1 at nth position only if nth bith of both are set, otherwise nth bit = 0

// Bitwise OR-> | -> returns bit = 0 at nth position only if nth bit of both operands are 0, 1 otherwise

//Bitwise ^ (XOR) -> returns bit = 1 at nth position only if the nth bits of both operands are different, otherwise 0

//Bitwise Left Shift << n -> left shifts the value in binary by n (padding it by 0s)

//Bitwise Right Shift >>n -> right shifts the value in binary by n

//Bitwise NOT ~ ->negates each bit






int main() {

  // Write C code here

  printf("Try programiz.pro");

  //Test bitwise operator

  unsigned char ch1, ch2, result;

  int n;

  printf("\n Enter two character values :");

  scanf("%c %c", &ch1, &ch2);

	printf("\n Enter any positive integer value n :");

	scanf("%d",&n);

   

  printf("\n The bit representation of %c : \n",ch1);

  printAllBitsOfChar(ch1);

   

  printf("\n The bit representation of %c : \n",ch2);

  printAllBitsOfChar(ch2);

   

  result = ch1&ch2;

  printf("\n (Testing Bitwise AND) %c&%c, result = %c, binary form : \n",ch1, ch2, result);

  printAllBitsOfChar(result);

   

  result = ch1|ch2;

  printf("\n (Testing Bitwise OR) %c|%c result = %c, binary form : \n",ch1, ch2, result);

  printAllBitsOfChar(result);

   

  result = ch1^ch2;

  printf("\n (Testing Bitwise XOR) %c^%c result = %c, binary form : \n", ch1, ch2,result);

  printAllBitsOfChar(result);

   

  result = ch1<<n;

  printf("\n (Testing Bitwise Left Shift) %c<<%d result = %c, binary form : \n",ch1, n, result);

  printAllBitsOfChar(result);

	

	result = ch1>>n;

  printf("\n (Testing Bitwise Right Shift) %c>>%d result = %c, binary form : \n",ch1, n, result);

  printAllBitsOfChar(result);

   

	result = ch2<<n;

  printf("\n (Testing Bitwise Left Shift) %c<<%d result = %c, binary form : \n",ch2, n, result);

  printAllBitsOfChar(result);

	

	result = ch2>>n;

  printf("\n (Testing Bitwise Right Shift) %c>>%d result = %c, binary form : \n",ch2, n, result);

  printAllBitsOfChar(result);

	

	result = ~ch1;

	printf("\n (Testing Bitwise NOT) ~%c result = %c, binary form : \n",ch1,  result);

  printAllBitsOfChar(result);

	

	result = ~ch2;

	printf("\n (Testing Bitwise NOT) ~%c result = %c, binary form : \n",ch2,  result);

  printAllBitsOfChar(result);

	

	

  return 0;

}
