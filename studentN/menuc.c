#include"admin.h"
#include"menuc.h"
#include<string.h>
#include"tool.h"
#include "struct.h"
#include"manager.h"
#include"supermanager.h"
#include<stdio.h>
//主界面
void major_menu(void)
{
	system("clear");
	puts("**********欢迎进入本校系统************");
	puts("          请选择登录入口             ");
	puts("          1、管理员登录             ");
	puts("          2、老师登录               ");
	puts("          0、保存退出               ");
	puts("-------------------------------------");
	puts("请输入登录方式：");
	
}	

//管理员登录菜单
void manager_menu(void)
{
	system("clear");
	puts("***普通用户***");
	puts("1、添加学生");
	puts("2、删除学生");
	puts("3、修改学生信息");
	puts("4、查询学生");
	puts("5、排序");
	puts("6、显示所有学生");
	puts("0、退出");
	printf("请输入：");
}

//超级管理员菜单
void super_manager_menu(void)
{
	system("clear");
	puts("***超级用户***");
	puts("1、添加普通用户");
	puts("2、删除普通用户");
	puts("3、修改普通用户信息");
	puts("4、显示所有用户");
	puts("0、退出");
	printf("请输入：");
}

//排序菜单
void sort_menu(void)
{
	system("clear");
	puts("1、语文排序");
	puts("2、数学排序");
	puts("3、英语排序");
	puts("0、退出");
	printf("请输入：");
}
