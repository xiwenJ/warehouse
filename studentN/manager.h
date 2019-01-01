#ifndef MANAGER_H
#define MANAGER_H
#include"tool.h"
#include"struct.h"

student* add_student(void);
void add_stu(List* list,TYPE data);
int find_list_s(List* list,int num);
void find_student(List* list);
bool del_student(List* list);
student* modify_student(void);
bool modify_stu(List* list);
void show_student(List*list);


void swap(Node* node1,Node* node2);
void chinese_sort(Node* head,Node* tail);
void math_sort(Node* head,Node* tail);
void english_sort(Node* head,Node* tail);
Node*  _binary_find(Node* node,int left,int right,int num);
Node* binary_find(Node* node,int count,int num);
void num_sort(Node *head,Node* tail);
void show_chinese(List*list);
void show_math(List*list);
void show_english(List*list);
#endif//MANAGER_H


