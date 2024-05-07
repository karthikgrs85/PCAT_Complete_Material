#include "StudentBinaryFile.h"
#include "Struct_SerializeDeserialize.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

extern int lastRollNo;

int writeDynArrToBinaryFile(const Student **s, int size, const char fName[])
{
	if(s==NULL)
		return -1;
		
	FILE *fp = fopen(fName,"wb");
	if(fp==NULL)
	{
		printf("\n Error writing to file ...\n");
		return -1;
	}
	Serialized_Student ss;
	int i;
	for(i =0;i<size;++i)
	{
		serialize(*s[i],&ss);		
		fwrite(&ss, sizeof(ss), 1, fp);
	}
	printf("\n %d elements successfully written to file \n",i);
	fclose(fp);
	

}

int appendDynArrToBinaryFile(const Student **s, int size, const char fName[])
{

	if(s==NULL)
		return -1;
		
	FILE *fp = fopen(fName,"ab");
	if(fp==NULL)
	{
		printf("\n Error writing to file ...\n");
		return -1;
	}
	Serialized_Student ss;
	int i;
	for(i=0;i<size;++i)
	{
		serialize(*s[i],&ss);		
		fwrite(&ss, sizeof(ss), 1, fp);
	}
	printf("\n %d elements successfully written to file \n",i);
	fclose(fp);

}


int readFromBinaryFile(Student ***s, int *size, const char fName[])
{
	FILE *fp = fopen(fName,"rb");
	if(fp==NULL)
	{
		printf("\n Error reading from file ...\n");
		return -1;
	}
	int i = 0;
	Serialized_Student ss[ARR_MAX];
	while(fread(&ss[i++], sizeof(Serialized_Student), 1, fp));
	*size = i-1;
	
	 
	
	printf("\n %d elements successfully read from file \n",*size);
	fclose(fp);
	
	if(*s!= NULL)
		free(*s);
	
	*s = (Student**)calloc(i, sizeof(Student*));
	for(i =0; i<*size; i++)
	{
		(*s)[i] = (Student*)malloc(sizeof(Student));
		deserialize(ss[i],(*s)[i]);	
	}
	
	printf("\n %d elements successfully deserialized \n",i);

}

int readLastRecordFromBinaryFile(const char fName[])
{
	FILE *fp = fopen(fName,"rb");
	if(fp==NULL)
	{
		printf("\n Error reading last record from file ...\n");
		return -1;
	}
	Serialized_Student ss;
	fseek(fp, -sizeof(Serialized_Student), SEEK_END);
	
	fread(&ss, sizeof(ss), 1, fp);
	lastRollNo = ss.rollno;
	//Getting last Roll No. from file
	printf("\n Retrieved Last Roll No. from binary file as %d\n",lastRollNo);
	return 1;
	
}

int deleteRecordFromBinaryFile(const char fName[], int rollNo)
{
	Student **sArr= NULL;
	int size = 0, index=-1;
	readFromBinaryFile(&sArr, &size, fName);
	if((index=getIndexForRollNo((const Student**)sArr, size, rollNo))==-1)
	{
		printf("\n Cannot delete record, no match found !...\n");
		return -1;
	
	}
	deleteIndexInDynArrOfStudents(sArr,&size,index);
	printf("\n Student record successfully deleted !..\n");
	return 1;

}
