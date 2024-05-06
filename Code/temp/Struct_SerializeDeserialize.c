// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_LEN 50
typedef struct
{
    char *fName, *lName; //pointer to dynamically allocated memory
    int rollno;
    
}Student;

typedef struct{
	char fName[BUF_LEN], lName[BUF_LEN];
	int rollno;
	
}Serialized_Student;

void serialize(Student s, Serialized_Student *ss)
{
	if(s.fName==NULL || s.lName==NULL)
		return;
	strncpy(ss->fName, s.fName, strlen(s.fName));
	ss->fName[strlen(s.fName)]='\0';
	
	strncpy(ss->lName, s.lName, strlen(s.lName));
	ss->lName[strlen(s.lName)]='\0';
	
	ss->rollno = s.rollno;
}

void deserialize(Serialized_Student ss, Student *s)
{
	s->fName = (char*)calloc(strlen(ss.fName)+1,sizeof(char));
    strncpy(s->fName, ss.fName,strlen(ss.fName) );
    ss.fName[strlen(ss.fName)]='\0';
	
	s->lName = (char*)calloc(strlen(ss.lName)+1,sizeof(char));
    strncpy(s->lName, ss.lName,strlen(ss.lName) );
    ss.lName[strlen(ss.lName)]='\0';
	
	s->rollno = ss.rollno;
}

typedef union 
{
 char *fName, *lName;
 int num;
}unionStu;

void initStudent(Student *stu)
{
    static int rollno = 1;
    char buf[BUF_LEN];
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
    printf("\n ------------------------");
    
}

void deleteStudent(Student *stu)
{
    printf("\n Deleting First Name %s ",stu->fName);
    
    free(stu->fName);
    
    printf("\n Deleting Last Name %s ",stu->lName);
    free(stu->lName);
}


int main() {
    // Write C code here
    printf("Try programiz.pro");
    Student s1, s2;
    int i, numStu = 0;
    
    Serialized_Student ss1;
    
    initStudent(&s1);
    
    
    
    
    printf("\n Original Deserialized Object s1 :\n");
    printStudentDetails(s1);
    
    
    serialize(s1, &ss1);
    
    deleteStudent(&s1);
    printf("\n Inside Serialized Object ss1 : \n");
    printf("\n First Name : %s", ss1.fName);
    printf("\n Last Name : %s", ss1.lName);
    printf("\n Roll No. : %d", ss1.rollno);
    s2.fName = NULL;
    s2.lName = NULL;
    deserialize(ss1,&s2);
    printf("\n Final Deserialized Object s2 :\n");
    printStudentDetails(s2);
    
    
    deleteStudent(&s2);
    
   
    
    
    
    return 0;
}