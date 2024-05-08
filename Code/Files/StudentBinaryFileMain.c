#include "Student.h"
#include "StudentBinaryFile.h"
#include "Struct_SerializeDeserialize.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define TMP_BUF_MAX 5
#define STRINGIZE(x) #x
#define FILENAME STRINGIZE(StudentRecords.bin)

#define INP_BUF_LEN 6
int main()
{
	int choice, size=0, sizeF=0, rollNo =0, index = -1;
	Student **sArr= NULL; //Local Array for data input by user
	Student  **sFileArr=NULL;//Array containing elements read by file
	char tmpBuf[TMP_BUF_MAX];
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
			"\n 6. Get a particular student record from local array"
			"\n 7. Get a particular student record from file"
			"\n 8. Delete a student record from local array"
			"\n 9. Delete a student record from file"
			"\n 10. Exit from program \n");
		scanf("%d",&choice);
		
		if(choice <1 || choice > 10)
		{
			printf("\n Invalid choice!...Try again...\n");
			continue;
		}
		else if(choice >=6 &&choice <=9)
		{
			getchar();
			printf("\n Enter RollNo :");
			fgets(tmpBuf,TMP_BUF_MAX, stdin); 
			rollNo = atoi(tmpBuf);
		
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
				if((index = getIndexForRollNo((const Student**)sArr, size, rollNo))!=-1)
				{
					printStudentDetails(*(sArr[index]));
				}
					
				break;
			case 7: readFromBinaryFile(&sFileArr, &sizeF, FILENAME);
				if((index = getIndexForRollNo((const Student**)sFileArr, sizeF, rollNo))!=-1)
				{
					printStudentDetails(*(sFileArr[index]));
				}
				deleteDynArrOfStudents(&sFileArr, sizeF);
				sFileArr = NULL;
				sizeF = 0;
				break;
			case 8:
				if((index = getIndexForRollNo((const Student**)sArr, size, rollNo))!=-1)
				{
					deleteIndexInDynArrOfStudents(sArr, &size, index);
				}
				break;
				
			case 9:
				deleteRecordFromBinaryFile(FILENAME, rollNo);
				break;
			case 10:
				break;
					
		
		}
	}while(choice != 10);


}
