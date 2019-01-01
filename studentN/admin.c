#include"admin.h"
#include"menuc.h"
#include<string.h>
#include"tool.h"
#include "struct.h"
#include"manager.h"
#include"supermanager.h"
#include<stdio.h>
	
//超级管理员登录
void super_admin()
{
	system("clear");
	char password[10]={};
	char name[20]={};
	int count=0;
	printf("请输入您的姓名：\n");
	gets(name);
	if(0==strcmp(name,"xiwen"))
	{
		while(count<3)
		{
			printf("请输入您的密码\n");
			hide(password);
			if(0==strcmp(password,"asd"))
			{
				while(1)
				{
					super_manager_menu();
					switch(get_cmd('0','4'))
					{
						case '1': add_ma(list_m,add_manager()); break;
						case '2': del_manager(list_m);	 break;
						case '3': modify_ma(list_m); break;
						case '4': show_manager(list_m);break;
						case '0': return ;
					}
				}			
			}
			else
			{
				printf("您的密码输入错误\n");
				count++;
			}
		}
		return ;
	}
}
//管理员登录
void manager_admin()
{
	system("clear");
	char password[10]={};
	char name[20]={};
	int count=0;
	printf("请输入您的姓名：\n");
	gets(name);
	if(find_list_m(list_m,name)!=-1 || 0 == strcmp(name,"xiwen"))
	{
		while(count<3)
		{
			int flag=0;
			int flag_x=0;
			if(0 == strcmp(name,"xiwen"))
			{
				flag_x=1;
			}
			printf("请输入您的密码\n");
			hide(password);
			if(0 == strcmp(name,"xiwen") && 0==strcmp(password,"asd"))
			{
				flag=1;
			}
			if(flag_x ==0 &&  0==strcmp(password,re_password(list_m,name))  || flag==1 )
			{
				while(1)
				{
					manager_menu();
					switch(get_cmd('0','6'))
					{
						case '1': add_stu(list_s,add_student()); break;
						case '2': del_student(list_s);break;
						case '3': modify_stu(list_s); break;
						case '4': find_student(list_s);break;
						case '5': sort_admin();  break;
						case '6': show_student(list_s);break;
						case '0': return;
					}
				}			
			}
			else
			{
				printf("您的密码输入错误\n");
				count++;
			}
		}
		return ;
	}
}

//排序功能登录
void sort_admin(void)
{
	while(1)
	{
		sort_menu();
		switch(get_cmd('0','3'))
		{
			case '1':chinese_sort(list_s->head,list_s->tail);show_chinese(list_s); break;
			case '2':math_sort(list_s->head,list_s->tail);show_math(list_s); break;
			case '3':english_sort(list_s->head,list_s->tail);show_english(list_s); break;
			case '0':return;
			
		}
	}
}





