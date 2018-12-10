#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<getch.h>
#include<stdbool.h>

typedef struct Cons
{
	char name[20];
	char sex;
	char tell[20];
}Cons;

Cons con[100];

int i=0;

bool is_sub(char *str1,char *str2)
{
	int k;
	for(k=0;str1[k];k++)
	{
	}
	for(int i=0;str1[i];i++)
	{
		int num=0;
		for(int j=0;str2[j];j++)
		{
			if(str1[i]==str2[j])
			{
				num++;
				i++;
			}
			
		}
		if(num==k)
		{
			return true;
		}
		return false;
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

void show(void)
{
	system("clear");
	printf("* * *欢迎使用指针电话簿* * *\n");
	printf("1、增加联系人：姓名 性别 电话\n");
	printf("2、删除联系人：按姓名、电话删除联系人\n");
	printf("3、修改联系人信息：按姓名修改联系人信息\n");
	printf("4、查询联系人：姓名\n");
	printf("5、显示所有联系人\n");
	printf("请输入指令：\n");
}

void add(void)
{
		system("clear");
		if(i==100)
		{
			printf("电话簿已满\n");
			return ;
		}
		if(con[i].sex==0)
		{
		scanf("%s",con[i].name);
		getchar();
		scanf("%c",&con[i].sex);
		scanf("%s",con[i].tell);}
		getch();
		i++;
}

void delete(void)
{
	char str[20]={};
	system("clear");
	printf("请输入联系人姓名或电话：\n");
	gets(str);

	for(int j=0;j<i;j++)
	{
		if((strcmp(con[j].name,str)==0 || strcmp(con[j].tell,str)==0) && con[j].sex!=0)
		{
					con[j].sex=0;
					printf("已删除\n");		
					getch();
					return ;
		}
	}
	printf("没有此人\n");
	getch();			

}

void modify(void)
{
	char n1[20]={};
	char n2;
	char n3[20]={};
	char str[20]={};
	system("clear");
	gets(str);
	for(int j=0;j<i;j++)
	{
		if(con[j].sex==0)
		{
			continue;
		}
		if(strcmp(con[j].name,str)==0)
		{
			printf("请输入新信息：\n");
			get_str(n1,20);
			strcpy(con[j].name,n1);
			scanf("%c",&n2);
			con[j].sex=n2;
			get_str(n3,12);
			strcpy(con[j].tell,n3);
			return ;
		}
	}
	printf("此人不存在\n");
	getch();
}

void find(void)
{
	char str[20]={};
	system("clear");
	gets(str);
	printf("查找结果为：\n");
	for(int j=0;j<i;j++)
	{
		if(con[j].sex==0)
		{
			continue;
		}
		if(is_sub(str,con[j].name))
		{
			printf("%s %c %s\n",con[j].name,con[j].sex,con[j].tell);
		}
		
	}
	getch();

}
void show_all(void)
{
	system("clear");
	for(int j=0;j<i;j++)
	{
		if(con[j].sex==0){
			continue;
		}
		printf("%s ",con[j].name);
		printf("%c ",con[j].sex);
		printf("%s\n",con[j].tell);
	}
	getchar();
}

int main()
{
	while(1)
	{
		show();
		switch(getch())
		{
			case '1':add();break;
			case '2':delete();break;
			case '3':modify();break;
			case '4':find();break;
			case '5':show_all();break;
		}
	}
}






