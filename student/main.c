#include <stdio.h>
#include <stdlib.h>
#include "admin.h"
#include "menuc.h"
#include "tool.h"
#include "struct.h"

void quit(void)
{	
	FILE* stu_w=fopen("stu.txt","w");
	for(int i=0;i<stu_count;i++)
	{
		fwrite(&stu[i],92,1,stu_w);
	}
	
	FILE* tea_w=fopen("tea.txt","w");
	for(int i=0;i<tea_count;i++)
	{
		fwrite(&tea[i],60,1,tea_w);
	}

	FILE* ma_w=fopen("ma.txt","w");
	for(int i=0;i<ma_count;i++)
	{
		fwrite(&ma[i],44,1,ma_w);
	}
}	



int main()
{
	
	stu_count=0;
 	tea_count=0;
 	ma_count=0;
	
	FILE* stu_r=fopen("stu.txt","r");
	fseek(stu_r,0,SEEK_END);
	long ret_stu=ftell(stu_r);
	rewind(stu_r);
	stu_count=ret_stu/92;
	for(int i=0;i<stu_count;i++)
	{
		fread(&stu[i],92,1,stu_r);
	}
	
	
	FILE* tea_r=fopen("tea.txt","r");
	fseek(tea_r,0,SEEK_END);
	long ret_tea=ftell(tea_r);
	rewind(tea_r);
	tea_count=ret_tea/60;
	for(int i=0;i<tea_count;i++)
	{
		fread(&tea[i],60,1,tea_r);
	}
	

	FILE* ma_r=fopen("ma.txt","r");
	fseek(ma_r,0,SEEK_END);
	long ret_ma=ftell(ma_r);
	rewind(ma_r);
	ma_count=ret_ma/44;
	for(int i=0;i<ma_count;i++)
	{
		fread(&ma[i],44,1,ma_r);
	}
	
	

	while(1)
	{
		major_menu();
		switch(get_cmd('0','4'))
		{
			case '1': manager_admin();break;
			case '2': teacher_admin();break;
			case '3': student_admin();break;
			case '0': quit();return 0;
			case '4': super_admin();break;
		}
	}
}





