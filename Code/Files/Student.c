#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Student.h"

#define BUF_LEN 50

int lastRollNo = 0;

void initStudent(Student *stu)
{
    lastRollNo++;
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
    
    
    stu->rollno = lastRollNo;
    
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

int initializeDynArrOfStudents(Student ***sArr, int *size)
{

	printf("\n Enter number of students to initialize :");
	scanf("%d",size);
	if(*size<1)
	{
		printf("\n Not a valid size \n");
		return -1;
	}
	getchar();
	*sArr = (Student**)calloc(*size, sizeof(Student*));
	int i;
	for(i = 0; i<*size;i++)
	{
		printf("\n Enter student details for student %d",i+1);
		(*sArr)[i]=(Student*)malloc(sizeof(Student));
		initStudent((*sArr)[i]);
	}
	
	printf("\n %d students initialized successfully \n",i);
	return 1;
}

int printDynArrOfStudents(const Student **sArr, int size)
{
	if(sArr==NULL || size <1)
	{
		printf("\n No valid elements in dynamic Student Array \n");
		return -1;
	
	}
	printf("\n Student Array Details :\n");

	for(int i = 0; i< size;++i)
	{
		printf("\n Student %d : \n",i+1);
		if(sArr[i]==NULL)
		{
			printf("\n Invalid data \n");
			return -1;
		}
		printStudentDetails(*sArr[i]);
	
	}

}

int deleteDynArrOfStudents(Student ***sArr, int size)
{
	if(sArr== NULL || *sArr == NULL)
	{
		printf("\n No data to delete !...\n");
		return -1;
	}
	for(int i = 0; i< size;i++)
	{
		if(((*sArr)[i])!=NULL)
		{
			free((*sArr)[i]);
			printf("\n Freeing student %d",i+1);
		}
		else
		{
			printf("\n Invalid data, cannot delete record %d\n",i+1);
			return -1;
		}
	
	}
	free(*sArr);
	printf("\n Freeing Dynamic Array \n");
	return 1;


}

