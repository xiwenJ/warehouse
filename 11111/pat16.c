#include<stdio.h>

int main()
{
	char str1[100]={};
	char str2[100]={};
	char n1,n2;
	scanf("%s %c %s %c",str1,&n1,str2,&n2);
	int num1=0;
	for(int i=0;str1[i];i++)
	{
		if(str1[i]==n1)
		{
			num1++;
		}
	}
	int num2=0;
	for(int i=0;str2[i];i++)
	{
		if(str2[i]==n2)
		{
			num2++;
		}
	}
	int n=0;
	n1=n1-'0';
	n2=n2-'0';
	for(int i=0;i<num1;i++)
	{
		n*=10;
		n+=n1;
	}
	int m=0;
	for(int i=0;i<num2;i++)
	{
		m*=10;
		m+=n2;
	}
	int k=n+m;
	printf("%d\n",k);
}
