#include "Student.h"
#include "StudentBinaryFile.h"
#include "Struct_SerializeDeserialize.h"
#include <stddef.h>
#include <stdio.h>

#define STRINGIZE(x) #x
#define FILENAME STRINGIZE(StudentRecords.bin)

#define INP_BUF_LEN 6
int main()
{
	int choice, size=0, sizeF=0;
	Student **sArr= NULL , **sFileArr=NULL;//Dynamic array of students
	//Update last roll no. from binary file
	readLastRecordFromBinaryFile(FILENAME);

	do
	{
		printf("\n Select from the following options :"
			"\n 1. Enter some student details to local dynamic array "
			"\n 2. Print the student details from local dynamic array "
			"\n 3. Write the array to file "
			"\n 4. Append the array to file "
			"\n 5. Read from file "
			"\n 6. Exit from program \n");
		scanf("%d",&choice);
		
		if(choice <1 || choice > 6)
		{
			printf("\n Invalid choice!...Try again...\n");
			continue;
		}	
		switch(choice)
		{
			case 1: initializeDynArrOfStudents(&sArr, &size);
				break;
			case 2: printDynArrOfStudents((const Student**)sArr, size);
				break;
			case 3: writeDynArrToBinaryFile((const Student**)sArr, size, FILENAME);
				deleteDynArrOfStudents(&sArr, size);
				sArr = NULL;
				size = 0;
				break;
			case 4: appendDynArrToBinaryFile((const Student**)sArr, size, FILENAME);
				deleteDynArrOfStudents(&sArr, size);
				sArr = NULL;
				size = 0;
				break;
			case 5: readFromBinaryFile(&sFileArr, &sizeF, FILENAME);
				printDynArrOfStudents((const Student**)sFileArr, sizeF);
				deleteDynArrOfStudents(&sFileArr, sizeF);
				sFileArr = NULL;
				sizeF = 0;
				break;
			case 6:
				break;
					
		
		}
	}while(choice != 6);


}
