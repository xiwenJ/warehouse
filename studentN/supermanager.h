#ifndef SUPERMANAGER_H
#define SUPERMANAGER_H
#include"tool.h"
#include"struct.h"


int find_list_m(List* list,char* name);

manager* add_manager(void);
void add_ma(List* list,TYPE data);
bool del_manager(List* list);
manager* modify_manager(void);
bool modify_ma(List* list);
void show_manager(List*list);
char* re_password(List* list,char* name);
#endif//SUPERMANAGER_H
