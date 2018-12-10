#include "tool.h"


void anykey_continue(void)
{
	puts("按任意键返回......");
	getch();
}

void show_msg(char* msg,int sec)
{
	printf("\033[01;31m%s\n\033[00m",msg);
	sleep(sec);
}

char get_cmd(char start,char end)
{
	while(1)
	{
		char cmd = getch();
		if(cmd >= start && cmd <= end)
		{
			printf("%c\n",cmd);
			return cmd;
		}
	}
}

