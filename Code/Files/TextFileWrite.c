#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_MAX 100


int main(int argc, char *argv[])
{
	if(argc!=3)
	{
		printf("\n Usage %s  "
			"\n  -WriteTo <FileToWriteDataTo>"
			"\n  -AppendTo <FileToWriteDataTo> \n",argv[0]);
		return -1;
	}
	FILE *fp= NULL;
	if(!strcmp(argv[1],"-WriteTo"))
	{
		fp = fopen(argv[2],"w");
		if(fp==NULL)
		{
			printf("\n File cannot be opened for writing !..\n");
			return -1;
		}
	}
	else if(!strcmp(argv[1],"-AppendTo"))
	{
		fp = fopen(argv[2],"a");
		if(fp==NULL)
		{
			printf("\n File cannot be opened for appending !..\n");
			return -1;
		}
	
	}
	char buf[BUF_MAX];
	int countLines = 0;
	printf("\n Enter some data (exit to finish writing) :\n");
	do
	{
		fgets(buf, BUF_MAX, stdin);
		buf[strlen(buf)]='\0';
		if(!strcmp(buf,"exit\n"))
			break;
		fputs(buf, fp);
		countLines++;	
		
	
	}while(1);
		
	printf("\n %d lines written successfully to file %s \n", countLines, argv[2]);
	fclose(fp);
	
	return 1;

}
