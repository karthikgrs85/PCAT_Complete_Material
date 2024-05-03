// Online C compiler to run C program online

#include <stdio.h>

#include <math.h>

#include <stdbool.h>

#include "BitWise.h"
#include "PrintBits.h"







int main() {

  // Write C code here

  printf("Try programiz.pro");

  //Test bitwise operator

  unsigned char ch, result;

  int x, y;

  printf("\n Enter any character:");

  scanf("%c", &ch);

  result = ch;

	printf("\n Enter 2 positive integers x, y (8>=x>y>=0) :");

	scanf("%d %d",&x, &y);

   

  printf("\n The bit representation of %c : \n",ch);

  printAllBitsOfUnsignedChar(ch);

   

  setNBits(&result, x, y);

  printf("\n After setting bits %d to %d, result = %c\n", y,x, result);

  printAllBitsOfUnsignedChar(result);

   

  result = ch;

  resetNBits(&result, x, y);

  printf("\n After resetting bits %d to %d, result = %c\n",y, x, result);

  printAllBitsOfUnsignedChar(result);
   

  result = ch;

  flipNBits(&result, x, y);

  printf("\n After flipping bits %d to %d, result = %c\n", y,x, result);

  printAllBitsOfUnsignedChar(result); 

//	testNthBit(ch, n)?(printf("\n The %d bit in %c is set \n", n, ch)):(printf("\n The %d bit in %c is not set \n", n, ch));

  return 0;

}
