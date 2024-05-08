
#include <stdio.h>
//#pragma warn +rvl

#ifndef __LOGS_ENABLED__
#define __LOGS_ENABLED__
#endif

#ifdef __LOGS_ENABLED__
#undef __LOGS_ENABLED__
#endif

#define _LOGS_PRIORITY_LEVEL 0



int main()
{
	printf("\n The program is saved as %s \n",__FILE__);

#ifdef __LOGS_ENABLED__
	printf("\n Logs enabled : The program is currently executing at line no. %d \n", __LINE__);
#endif

#if _LOGS_PRIORITY_LEVEL == 1
	printf("\n PRIORITY LOGS = 1, the program is currently executing at line no. %d \n", __LINE__);
#elif _LOGS_PRIORITY_LEVEL ==2
	printf("\n PRIORITY LOGS = 2, the program is currently executing at line no. %d \n", __LINE__);
#endif
	printf("\n The current Time is %s \n", __TIME__);
	printf("\n The compiler standard is %d \n",__STDC__);
	//return 1;	

}
