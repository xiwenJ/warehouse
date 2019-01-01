#include"supermanager.h"
#include"tool.h"
#include<stdlib.h>
#include "struct.h"



//添加管理员函数
manager* add_manager(void)
{
	system("clear");
	manager* ma=malloc(sizeof(manager));
	printf("请输入工号：\n");
	scanf("%d",&(ma->ma_num));
	getchar();
	printf("请输入密码：\n");
	hide(ma->password);
	printf("请输入姓名：\n");
	gets(ma->name);
	printf("请输入性别:\n");
	scanf("%c",&(ma->sex));
	printf("请输入出生年：\n");
	scanf("%d",&(ma->age));
	getchar();
	return ma;
}

//修改管理员函数
manager* modify_manager(void)
{
	system("clear");
	manager *ma=malloc(sizeof(manager));
	printf("请输入工号：\n");
	scanf("%d",&(ma->ma_num));
	getchar();
	printf("请输入密码：\n");
	hide(ma->password);
	printf("请输入姓名：\n");
	gets(ma->name);
	printf("请输入性别:\n");
	scanf("%c",&(ma->sex));
	printf("请输入出生年：\n");
	scanf("%d",&(ma->age));
	getchar();
	return ma;

}

// 根据学号查找
int find_list(List* list,int ma_num)
{
	Node* node = list->head;
	for(int i=0; i<list->count; i++)
	{
		manager*ma=node->data;
		if(ma->ma_num == ma_num)
			return i;
		node = node->next;
	}

	return -1;
}

//根据姓名查找
int find_list_m(List* list,char* name)
{
	Node* node = list->head;
	for(int i=0; i<list->count; i++)
	{
		manager*ma=node->data;
		if(0 == strcmp(ma->name,name))
			return i;
		node = node->next;
	}

	return -1;
}




//在链表中添加节点
void add_ma(List* list,TYPE data)
{
	Node* node = create_node(data);

	// 判断链表是否为空
	if(empty_list(list))
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}

	list->count++;
	anykey_continue();
}

//删除管理员
bool del_manager(List* list)
{
	system("clear");
	int ma_num;
	printf("请输入你要删除的用户的工号：\n");
	scanf("%d",&ma_num);
	getchar();
	int index;
	bool flag = false;
	while((index = find_list(list,ma_num))!=-1)
	{
		if(!delete_index_list(list,index))
		break;
		flag = true; 
	}
	if(flag == true)
	{
		printf("已经删除\n");
	}
	else
	{
		printf("删除失败\n");
	}
	anykey_continue();
}	 

//在链表中修改
bool modify_ma(List* list)
{
	system("clear");
	int ma_num;
	printf("请输入您要修改的用户的工号：\n");
	scanf("%d",&ma_num);
	manager* n=modify_manager();
	bool flag = false;
	for(Node* node=list->head; node; node=node->next)
	{
		manager* ma=node->data;
		if(ma_num == ma->ma_num)
		{
			void * temp=node->data;
			free(temp);
			node->data = n;
			flag = true;
		}
	}
	if(flag == true)
	{
		printf("已经修改\n");
	}
	else
	{
		printf("修改失败\n");
	}
	anykey_continue();
}

//显示管理员
void show_manager(List*list)
{
	system("clear");
	if(empty_list(list))
	{
		printf("无\n");
		anykey_continue();
		return;
	}
	for(Node* node=list->head; node; node=node->next)
	{
		manager* ma=node->data;
		printf("工号：%d ",ma->ma_num);
		printf("姓名：%s ",ma->name);
		printf("性别：%s ",ma->sex == 'm'?"男":"女");
		printf("年龄：%d ",ss/SEC-(ma->age-1970));
		printf("\n");
	}
	printf("\n");
	anykey_continue();
	return;
}

//按姓名核实管理员密码
char* re_password(List* list,char* name)
{
	Node* node = list->head;
	for(int i=0; i<list->count; i++)
	{
		manager*ma=node->data;
		if(0 == strcmp(ma->name,name))
		{
			return ma->password;
		}
		node = node->next;
	}
}




