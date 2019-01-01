#include "tool.h"
#include<string.h>
#include<getch.h>
#include"struct.h"


//按任意键返回
void anykey_continue(void)
{
	puts("按任意键返回......");
	getch();
}

//显示信息在屏幕，停留sec秒
void show_msg(char* msg,int sec)
{
	printf("\033[01;31m%s\n\033[00m",msg);
	sleep(sec);
}

//获取按键
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

void clear_stdin(void)
{
	stdin->_IO_read_ptr=stdin->_IO_read_end;
}

char* get_str(char* str,size_t size)
{
	if(NULL==str) return str;
	clear_stdin();
	fgets(str,size,stdin);
	if(size-1 == strlen(str))
	{
		if('\n' == str[size-2])
			str[size-2] = '\0';
		else
			clear_stdin();
	}
	else
		str[strlen(str)-1]='\0';
}

//隐藏密码函数
void hide(char *pass)
{
	for(int i = 0;i<10;i++)
	{
		pass[i] = getch();
		if(i==0 && 127==pass[i])
		{	
			i--;
			printf("\b \b");
			continue;
		}
		if(i>0&&127 == pass[i])
		{
			i-=2;	
			printf("\b \b");
			continue;
		}
		if('\n' == pass[i])
		{
			pass[i] = '\0';
			break;
		}
		putchar('*');
	}
	printf("\n");
}

//保存函数
void quit(void)
{	
	FILE* stu_w=fopen("stu.txt","w");
	if(stu_w==NULL)
	{
		perror("fopen");
		return;
	}
	for(Node* node=list_s->head;node;node=node->next)
	{
		char *str=node->data;
		for(int i=0;i<sizeof(student);i++)
		{
			str[i]=str[i]^code;
		}
		void* dat=str;
		student* stu=dat;
		fwrite(stu,sizeof(student),1,stu_w);
	}
	fclose(stu_w);
	stu_w=NULL;
	

	FILE* ma_w=fopen("ma.txt","w");
	if(ma_w==NULL)
	{
		perror("fopen");
		return;
	}
	for(Node* node=list_m->head;node;node=node->next)
	{
		char *str=node->data;
		for(int i=0;i<sizeof(manager);i++)
		{
			str[i]=str[i]^code;
		}
		void* dat=str;
		manager* ma=dat;
		fwrite(ma,sizeof(manager),1,ma_w);
	}
	fclose(ma_w);
	return;
}	

//加载文件函数
void init(void)
{
	void* data;
	FILE* stu_r=fopen("stu.txt","r");
	if(stu_r==NULL)
	{
		perror("fopen");
		return ;
	}
	fseek(stu_r,0,SEEK_END);
	long ret_stu=ftell(stu_r);
	rewind(stu_r);
	int stu_count=ret_stu/(sizeof(student));
	for(int i=0;i<stu_count;i++)
	{
		Node* node=create_node(data);
		student* stu=malloc(sizeof(student));
		fread(stu,sizeof(student),1,stu_r);
		node->data=stu;
		char *str=node->data;
		for(int i=0;i<sizeof(student);i++)
		{
			str[i]=str[i]^code;
		}
		void* dat=str;
		node->data=dat;
		if(0==list_s->count)
	    {
			list_s->head =node;
			list_s->tail=node;
	    }
	    else
	    {
			list_s->tail->next=node;
			list_s->tail=node;
	    }
	    list_s->count++;
	}
	fclose(stu_r);
	stu_r=NULL;
	

	FILE* ma_r=fopen("ma.txt","r");
	if(ma_r==NULL)
	{
		perror("fopen");
		return ;
	}
	fseek(ma_r,0,SEEK_END);
	long ret_ma=ftell(ma_r);
	rewind(ma_r);
	int ma_count=ret_ma/(sizeof(manager));
	for(int i=0;i<ma_count;i++)
	{
		Node* node=create_node(data);
		manager* ma=malloc(sizeof(manager));
		fread(ma,sizeof(manager),1,ma_r);
		node->data=ma;
		char *str=node->data;
		for(int i=0;i<sizeof(manager);i++)
		{
			str[i]=str[i]^code;
		}
		void* dat=str;
		node->data=dat;
		if(0==list_m->count)
	    {
			list_m->head =node;
			list_m->tail=node;
	    }
	    else
	    {
			list_m->tail->next=node;
			list_m->tail=node;
	    }
	    list_m->count++;
	}
	fclose(ma_r);
	ma_r=NULL;
	
}

//创建节点
Node* create_node(TYPE data)
{
	Node* node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

//创建链表
List* create_list(void)
{
	List* list= malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	list->count = 0;
	return list;
}

// 销毁链表
void destory_list(List* list)
{
	while(list->count)
	{
		Node* node = list->head;
		list->head = node->next;
		free(node);
		list->count--;
	}
	free(list);
}

// 判空
bool empty_list(List* list)
{
	return !list->count;
}

// 删除-按位置
bool delete_index_list(List* list,size_t index)
{
	if(index >= list->count)
		return false;
	
	Node* temp = list->head;
	if(0 == index)
		list->head = temp->next;
	else
	{
		Node* node = list->head;
		for(int i=0; i<index-1; i++)
		node = node->next;
		temp = node->next;
		node->next = temp->next;
		if(temp == list->tail)
		{
			list->tail=node;
		}
	}
	list->count--;
	free(temp->data);
	free(temp);
	return true;
	/*Node* prev=list->head;
	while(prev->next)
	{
		if(prev->next->num==num)
		{
			Node* cur=prev->next;
			Node* next=cur->next;
			prev->next=next;
			list->count--;
			free(cur->data);
			free(cur);
			return true;
		}
		prev=prev->next;
	}
	return false;*/
}

