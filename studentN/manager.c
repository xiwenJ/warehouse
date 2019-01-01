#include"manager.h"
#include"tool.h"
#include<stdlib.h>
#include "struct.h"
#include"supermanager.h"

//添加学生函数
student* add_student(void)
{
	system("clear");
	student* stu=malloc(sizeof(student));
	printf("请输入学号：\n");
	scanf("%d",&(stu->num));
	getchar();
	printf("请输入姓名：\n");
	gets(stu->name);
	printf("请输入性别:\n");
	scanf("%c",&(stu->sex));
	printf("请输入出生年：\n");
	scanf("%d",&(stu->age));
	printf("请输入语文成绩：\n");
	scanf("%g",&(stu->chinese));
	printf("请输入数学成绩：\n");
	scanf("%g",&(stu->math));
	printf("请输入英语成绩：\n");
	scanf("%g",&(stu->english));
	getchar();
	return stu;
}

//根据学号查找学生
int find_list_s(List* list,int num)
{
	Node* node = list->head;
	for(int i=0; i<list->count; i++)
	{
		student* stu=node->data;
		if(stu->num == num)
			return i;
		node = node->next;
	}

	return -1;

}

//二分法查找学生
void find_student(List* list)
{
	system("clear");
	int num;
	printf("请输入您要查找的学生的学号：\n");
	scanf("%d",&num);
	getchar();
	num_sort(list->head,list->tail);
	Node* node=binary_find(list->head,list->count,num);
	if(NULL == node)
	{
		printf("没有此人\n");
		anykey_continue();
		return ;
	}
	student* stu=node->data;
	printf("学号：%d ",stu->num);
	printf("姓名：%s ",stu->name);
	printf("性别：%s ",stu->sex == 'm'?"男":"女");
	printf("年龄：%d ",ss/SEC-(stu->age-1970));
	printf("语文成绩: %g ",stu->chinese);
	printf("数学成绩：%g ",stu->math);
	printf("英语成绩：%g ",stu->english);
	anykey_continue();
}

//在链表中添加节点
void add_stu(List* list,TYPE data)
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

//删除学生
bool del_student(List* list)
{
	system("clear");
	int num;
	printf("请输入你要删除的学生的学号：\n");
	scanf("%d",&num);
	getchar();
	int index = 0 , flag = false;
	while((index = find_list_s(list,num))!=-1)
	{
		delete_index_list(list,index);
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

//修改学生函数
student* modify_student(void)
{
	system("clear");
	student* stu=malloc(sizeof(student));
	printf("请输入学号：\n");
	scanf("%d",&(stu->num));
	getchar();
	printf("请输入姓名：\n");
	gets(stu->name);
	printf("请输入性别:\n");
	scanf("%c",&(stu->sex));
	printf("请输入出生年：\n");
	scanf("%d",&(stu->age));
	printf("请输入语文成绩：\n");
	scanf("%g",&(stu->chinese));
	printf("请输入数学成绩：\n");
	scanf("%g",&(stu->math));
	printf("请输入英语成绩：\n");
	scanf("%g",&(stu->english));
	getchar();
	return stu;

}

//在链表中修改
bool modify_stu(List* list)
{
	system("clear");
	int num;
	printf("请输入要修改的学生的学号：\n");
	scanf("%d",&num);
	student* n=modify_student();
	bool flag = false;
	for(Node* node=list->head; node; node=node->next)
	{
		student* stu=node->data;
		if( num== stu->num)
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

//显示学生函数
void show_student(List*list)
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
		student* stu=node->data;
		printf("学号：%d ",stu->num);
		printf("姓名：%s ",stu->name);
		printf("性别：%s ",stu->sex == 'm'?"男":"女");
		printf("年龄: %d ",ss/SEC-(stu->age-1970));
		printf("语文成绩: %g ",stu->chinese);
		printf("数学成绩：%g ",stu->math);
		printf("英语成绩：%g ",stu->english);
		printf("\n");
	}
	printf("\n");
	anykey_continue();
	return ;
}

//交换节点函数
void swap(Node* node1,Node* node2)
{
	void* temp=node1->data;
	node1->data=node2->data;
	node2->data=temp;
}

//语文成绩快排
void chinese_sort(Node* head,Node* tail)
{
	if(NULL==head||NULL==tail||head==tail) return;
	Node* flag=head;
	Node* prev=head;
	Node* cur=head->next;
	
	while(cur!=tail->next)
	{
		student* stu_f=flag->data;
		student* stu_c=cur->data;
		if(stu_f->chinese>stu_c->chinese)
		{
			prev=prev->next;
			swap(prev,cur);
		}
		cur=cur->next;
	}
	swap(prev,flag);
	chinese_sort(head,prev);
	chinese_sort(prev->next,tail);
}

//数学成绩快排
void math_sort(Node* head,Node* tail)
{
	if(NULL==head||NULL==tail||head==tail) return;
	Node* flag=head;
	Node* prev=head;
	Node* cur=head->next;
	
	while(cur!=tail->next)
	{
		student* stu_f=flag->data;
		student* stu_c=cur->data;
		if(stu_f->math>stu_c->math)
		{
			prev=prev->next;
			swap(prev,cur);
		}
		cur=cur->next;
	}
	swap(prev,flag);
	math_sort(head,prev);
	math_sort(prev->next,tail);
}

//英语成绩快排
void english_sort(Node *head,Node* tail)
{
	if(NULL==head||NULL==tail||head==tail) return;
	Node* flag=head;
	Node* prev=head;
	Node* cur=head->next;
	
	while(cur!=tail->next)
	{
		student* stu_f=flag->data;
		student* stu_c=cur->data;
		if(stu_f->english>stu_c->english)
		{
			prev=prev->next;
			swap(prev,cur);
		}
		cur=cur->next;
	}
	swap(prev,flag);
	english_sort(head,prev);
	english_sort(prev->next,tail);
}

//学号大小快排
void num_sort(Node *head,Node* tail)
{
	if(NULL==head||NULL==tail||head==tail) return;
	Node* flag=head;
	Node* prev=head;
	Node* cur=head->next;
	
	while(cur!=tail->next)
	{
		student* stu_f=flag->data;
		student* stu_c=cur->data;
		if(stu_f->num>stu_c->num)
		{
			prev=prev->next;
			swap(prev,cur);
		}
		cur=cur->next;
	}
	swap(prev,flag);
	num_sort(head,prev);
	num_sort(prev->next,tail);
}

//链表二分法函数
Node*  _binary_find(Node* node,int left,int right,int num)
{
	if(left >=right) return NULL;
	int p = (left+right)/2;
	for(int i=0;i<p;i++)
	{
		node=node->next;
	}
	student *stu=node->data;
	if( stu->num == num) return node;
	if( stu->num > num)
		return _binary_find(list_s->head,left,p,num);
	else
		return _binary_find(list_s->head,p+1,right,num);
}

Node* binary_find(Node* node,int count,int num)
{
	return _binary_find(node,0,count,num);
}


//显示学生语文成绩函数
void show_chinese(List*list)
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
		student* stu=node->data;
		printf("学号：%d ",stu->num);
		printf("姓名：%s ",stu->name);
		printf("性别：%s ",stu->sex == 'm'?"男":"女");
		printf("年龄: %d ",ss/SEC-(stu->age-1970));
		printf("语文成绩: %g ",stu->chinese);
		printf("\n");
	}
	printf("\n");
	anykey_continue();
	return ;
}

//显示学生数学成绩函数
void show_math(List*list)
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
		student* stu=node->data;
		printf("学号：%d ",stu->num);
		printf("姓名：%s ",stu->name);
		printf("性别：%s ",stu->sex == 'm'?"男":"女");
		printf("年龄: %d ",ss/SEC-(stu->age-1970));
		printf("数学成绩：%g ",stu->math);
		printf("\n");
	}
	printf("\n");
	anykey_continue();
	return ;
}


//显示学生英语成绩函数
void show_english(List*list)
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
		student* stu=node->data;
		printf("学号：%d ",stu->num);
		printf("姓名：%s ",stu->name);
		printf("性别：%s ",stu->sex == 'm'?"男":"女");
		printf("年龄: %d ",ss/SEC-(stu->age-1970));
		printf("英语成绩：%g ",stu->english);
		printf("\n");
	}
	printf("\n");
	anykey_continue();
	return ;
}

