#include "Student.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
	
	
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
