#ifndef TOOL_H
#define TOOL_H
#include<stdio.h>
#include<getch.h>
#include<stdlib.h>
#include<string.h>
#include"struct.h"
void anykey_continue(void);
void show_msg(char* msg,int sec);
char get_cmd(char start,char end);
void clear_stdin(void);
char* get_str(char* str,size_t size);
void hide(char *pass);
void quit(void);
void init(void);

Node* create_node(TYPE data);
List* create_list(void);
void destory_list(List* list);
bool empty_list(List* list);
bool delete_index_list(List* list,size_t index);


#endif

