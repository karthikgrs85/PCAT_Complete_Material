#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_LEN 50

typedef struct
{
    unsigned int day:5 ;//1-31 (<2^5 bits)
    unsigned int month:4; //1-12 (<2^4 bits)
    unsigned int year:11; //never exceed 2048 (<2^11)
}Date_bitfield;

typedef struct
{
    char nameCode: 4;
    char specialCode:2;
    int empno:32;
    
    
}Empno_bitfield;


typedef struct
{
    int day;
    int month;
    int year;
}Date_normal;
    


int main()
{
	
	printf("\n Sizeof Normal Date Struct = %lu \n",sizeof(Date_normal));
	printf("\n Sizeof Bitfield Date Struct = %lu \n",sizeof(Date_bitfield));
	printf("\n Sizeof EmployeeNo Bitfield Struct = %lu \n",sizeof(Empno_bitfield));
	
	

}
