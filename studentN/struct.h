#ifndef STRUCT_H
#define STRUCT_H

#define super_password asd
#include<getch.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define SEC (3600*24*365)
#define TYPE void*
#define code 123


//学生结构体
typedef struct student
{
	int  num;
	char name[20];
	char sex;
	int age;
	float chinese;
	float math;
	float english;
}student;

//管理员结构体
typedef struct manager 
{
	int ma_num;
	char password[10];
	char name[20];
	char sex;
	int age;
}manager;

//节点结构体
typedef struct Node
{
	TYPE data;
	struct Node* next;
}Node;

//链表结构体
typedef struct List
{
	Node* head;
	Node* tail;
	size_t count;
}List;

List* list_m;
List* list_s; 
int ss;

#endif//STRUCT_H



