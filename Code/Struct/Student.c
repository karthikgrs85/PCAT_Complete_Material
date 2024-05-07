#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Student.h"

#define BUF_LEN 50

void initStudent(Student *stu)
{
    static int rollno = 1;
    char buf[BUF_LEN];
    char *dtVal = NULL;
    printf("\n Enter First Name :");
    fgets(buf, BUF_LEN, stdin);
    buf[strlen(buf)-1]='\0';
    stu->fName = (char*)calloc(strlen(buf)+1,sizeof(char));
    strcpy(stu->fName, buf);
    
    printf("\n Enter Last Name :");
    fgets(buf, BUF_LEN, stdin);
    buf[strlen(buf)-1]='\0';
    stu->lName = (char*)calloc(strlen(buf)+1,sizeof(char));
    strcpy(stu->lName, buf);
    
    
    printf("\n Enter date joined :");
	
    printf("\n Enter day dd/mm/yyyy :");
    fgets(buf, BUF_LEN, stdin);
    buf[strlen(buf)-1]='\0';
    dtVal = strtok(buf,"/");
    if(dtVal!= NULL)
    {
        //printf("\n Day = %s ",dtVal);
        stu->dt_joined.day = atoi(dtVal);
    }
        
    dtVal = strtok(NULL,"/");
    if(dtVal!= NULL)
    {
        //printf("\n Month = %s ",dtVal);
        stu->dt_joined.month = atoi(dtVal);
    }
    
    
    dtVal = strtok(NULL,"/");
    if(dtVal!= NULL)
    {
        //printf("\n Year = %s ",dtVal);
        stu->dt_joined.year = atoi(dtVal);
    }
    
    
    stu->rollno = rollno++;
    
}

void printStudentDetails(Student s)
{
    if(s.fName==NULL || s.lName==NULL)
    {
        printf("\n Student First Name and Last Name not initialized !..\n");
        
    }
    
    printf("\n ------------------------");
    printf("\n Details of Student : \n");
    printf("\n ------------------------");
    printf("\n First Name : %s", s.fName);
    printf("\n Last Name : %s", s.lName);
    printf("\n Roll No. : %d", s.rollno);
	printf("\n Date Joined : %d/%d/%d \n",s.dt_joined.day, s.dt_joined.month, s.dt_joined.year);
    printf("\n ------------------------");
    
}

void deleteStudent(Student *stu)
{
    free(stu->fName);
    free(stu->lName);
}

void initializeDynArrOfStudents(Student **sArr, int *size)
{ 
    int i;
   
    
    printf("\n Enter number of students :\n");
    scanf("%d", size);
    //Use getchar to prevent \n in console input due to scanf from flowing through
    getchar();
    
    *sArr = (Student*)calloc(*size, sizeof(Student));
    for(i = 0; i< *size; ++i)
    {
        printf("\n Enter Student Details for student %d \n", i+1);
        initStudent(&sArr[i]);
    }
    printf("\n %d Students successfully initialized \n",i);
    
}

void printDynArrOfStudents(const Student *sArr, int size)
{
	if(size==0 || sArr==NULL)
	{
		printf("\n No data in Dynamic Array of Students \n");
		return;
	
	}
	
	printf("\n Student Details \n");
	for(int i = 0;i<size;++i)
	{
		printf("\n Student %d  \n",i+1);
		printStudentDetails(sArr[i]);
	
	}


}


