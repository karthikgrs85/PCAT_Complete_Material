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
    free(stu->fName);
    free(stu->lName);
}


int main() {
    // Write C code here
    printf("Try programiz.pro");
    Student s1;
    int i, numStu = 0;
    Student *sArr;
    
    printf("\n Enter number of students :\n");
    scanf("%d", &numStu);
    //Use getchar to prevent \n in console input due to scanf from flowing through
    getchar();
    sArr = (Student*)calloc(numStu, sizeof(Student));
    for(i = 0; i< numStu; ++i)
    {
        printf("\n Enter Student Details for student %d \n", i+1);
        initStudent(&sArr[i]);
    }
    
    for(i = 0; i< numStu; ++i)
    {
        printf("\n Student Details for student %d \n", i+1);
        printStudentDetails(sArr[i]);
    }
    for(i = 0; i< numStu; ++i)
    {
        printf("\n Deleting student details for student %d \n", i+1);
        deleteStudent(&sArr[i]);
    }
    free(sArr);
    printf("\n Freeing Dynamic Array sArr");
    
    
    
    return 0;
}