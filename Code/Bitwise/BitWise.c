#include "BitWise.h"
#include "PrintBits.h"
#include <stdio.h>

#define MAX_RANGE_SIZE 8 

//LSB -> Least Significant Bit
//MSB -> Most Significant bit

//n is counted from LSB

//10110

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
  //unsigned char result = a|(1<<(n-1);

}

void setNBits(unsigned char *a, int x, int y)
{
	
	if(x<y || x>MAX_RANGE_SIZE || y>MAX_RANGE_SIZE)
	{
		printf("\n Invalid range....\n");	
		return;
	}
	
	unsigned char val = getValueForRange(*a, x, y);
	(*a)|=(val);

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


void resetNBits(unsigned char *a, int x, int y)
{
	
	if(x<y || x>MAX_RANGE_SIZE || y>MAX_RANGE_SIZE)
	{
		printf("\n Invalid range....\n");	
		return;
	}
	
	unsigned char val = getValueForRange(*a, x, y);
	(*a)&=~(val);

}


//Flip a nth bit, n = 1

//^=(1<<(n-1))

//^=(1<<(1-1))

// a = (1100001)^(1)

// 1100000

//Flip and reset are same
void flipNthBit(unsigned char *a, int n)

{

  (*a)^=(1<<(n-1)); 

}


void flipNBits(unsigned char *a, int x, int y)
{
	
	if(x<y || x>MAX_RANGE_SIZE || y>MAX_RANGE_SIZE)
	{
		printf("\n Invalid range....\n");	
		return;
	}
	unsigned char val = getValueForRange(*a, x, y);
	(*a)^=val;

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



//For a range of bits    x...y
//Get a binary number 00011111000
//number = 1<<x-(1<<(y-1))
//Perform the same operation |=(), &=~()
//Example: a = 01100001
//Set all bits from 3 to 5
//number  = 00011100
// =  (00100000)- (10)
// =   00011100
// 1<<5 -(1<<(3-1))

//x is the start idx of the range
//y is the end idx of the range
unsigned char getValueForRange(unsigned char a, int x, int y)
{
	unsigned char val = '0';
	if(x<y || x>MAX_RANGE_SIZE || y>MAX_RANGE_SIZE)
	{
		printf("\n Invalid range....\n");	
		return val;
	}
	
	val = ((1<<x) -(1<<(y-1)));
	//printAllBitsOfUnsignedChar(val);
	return val;
}

