#pragma once

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
    char *fName, *lName; //pointer to dynamically allocated memory
    int rollno;
    Date_bitfield dt_joined;
    
}Student;

typedef union 
{
 char fName, lName;
 int rollno;
}unionStu;

void initStudent(Student *stu);

void printStudentDetails(Student s);

void deleteStudent(Student *stu);
