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
        printf("\n Day = %s ",dtVal);
        stu->dt_joined.day = atoi(dtVal);
    }
        
    dtVal = strtok(NULL,"/");
    if(dtVal!= NULL)
    {
        printf("\n Month = %s ",dtVal);
        stu->dt_joined.month = atoi(dtVal);
    }
    
    
    dtVal = strtok(NULL,"/");
    if(dtVal!= NULL)
    {
        printf("\n Year = %s ",dtVal);
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



int main()
{
	
	
/*	printf("\n Sizeof Normal Date Struct = %lu \n",sizeof(Date_normal));
	printf("\n Sizeof Bitfield Date Struct = %lu \n",sizeof(Date_bitfield));
	printf("\n Sizeof EmployeeNo Bitfield Struct = %lu \n",sizeof(Empno_bitfield));
*/	
	
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
}