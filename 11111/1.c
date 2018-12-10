#include<stdio.h>

struct student 
{
	char name[20];
	char sex;
	char num[20];
	char banji[30];
	
};

int main()
{
	struct student stu;
	scanf("%s",stu.name);
	getchar();
	scanf("%c",&stu.sex);
	scanf("%s",stu.num);
	scanf("%s",stu.banji);
	printf("%s %c %s %s",stu.name,stu.sex,stu.num,stu.banji);
}
