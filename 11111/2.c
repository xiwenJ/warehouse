#include<stdio.h>
#include<stdlib.h>

typedef struct Cons
{
	char name[20];
	char sex;
	char tel[20];
}Cons;


int main()
{
	Cons con[100];
	for(int i=0;i<2;i++)
	{
		scanf("%s",con[i].name);
		getchar();
		scanf("%c",&con[i].sex);
		scanf("%s",con[i].tel);
	}
	for(int i=0;i<2;i++)
	{
		printf("%s %s %s\n",(con+i)->name,(con+i)->sex=='1'?"男":"女",(con+i)->tel);
	}
}
