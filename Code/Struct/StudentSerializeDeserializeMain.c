#include "Student.h"
#include "Struct_SerializeDeserialize.h"
#include <stdio.h>

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

    deserialize(ss1,&s2);
    printf("\n Final Deserialized Object s2 :\n");
    printStudentDetails(s2);
    
    
    deleteStudent(&s2);
    
   
    
    
    
    return 0;
}
