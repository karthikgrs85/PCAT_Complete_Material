#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_LEN 50


typedef struct
{
    char fName, lName; //pointer to dynamically allocated memory
    int rollno;
    
}Student;

typedef union 
{
 char fName, lName;
 int rollno;
}unionStu;


int main()
{
	Student s;
	unionStu sU;
	
	printf("\n Sizeof Struct Student object s = %d \n", sizeof(s));
	
	printf("\n Sizeof Union Student object sU = %d \n", sizeof(sU));
	
	sU.rollno = 1;
	printf("\n After setting rollno to 1 inside Union object sU \n");
	printf("\n rollno : %d ", sU.rollno);
	printf("\n fName : %c ", sU.fName);
	printf("\n lName : %c \n", sU.lName);
	
	sU.fName = 'G';
	printf("\n After setting fName to G inside Union object sU \n");
	printf("\n rollno : %d ", sU.rollno);
	printf("\n fName : %c ", sU.fName);
	printf("\n lName : %c \n", sU.lName);
	
	sU.fName = 'K';
	printf("\n After setting lName to K inside Union object sU \n");
	printf("\n rollno : %d ", sU.rollno);
	printf("\n fName : %c ", sU.fName);
	printf("\n lName : %c \n", sU.lName);
}