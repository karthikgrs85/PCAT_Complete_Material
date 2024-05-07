#include "Struct_SerializeDeserialize.h"
#include "Student.h"
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

void serialize(Student s, Serialized_Student *ss)
{
	if(s.fName==NULL || s.lName==NULL)
		return;
	strncpy(ss->fName, s.fName, strlen(s.fName));
	ss->fName[strlen(s.fName)]='\0';
	
	strncpy(ss->lName, s.lName, strlen(s.lName));
	ss->lName[strlen(s.lName)]='\0';
	
	ss->dt_joined = s.dt_joined;
	
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
	
	s->dt_joined = ss.dt_joined;
	
	s->rollno = ss.rollno;
}


