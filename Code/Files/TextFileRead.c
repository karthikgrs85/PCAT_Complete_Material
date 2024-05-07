#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_MAX 100

int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		printf("\n Usage %s  <FileToReadDatafrom> \n",argv[0]);
		return -1;
	}
	
	FILE *fp = fopen(argv[1], "r");
	if(fp==NULL)
	{
		printf("\n Invalid File Name or File doesn't exist !..\n");
		return -1;
	}
	char buf[BUF_MAX] ="";
	while(fgets(buf, BUF_MAX, fp)!=NULL)
	{
		
		//buf[strlen(buf)]='\0';
		printf("%s",buf);
		strcpy(buf,"");
	}
	
	fclose(fp);
	
	return 1;

}
