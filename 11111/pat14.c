#include<stdio.h>
#include<string.h>

int main()
{
	char str1[61]={};
	char str2[61]={};
	char str3[61]={};
	char str4[61]={};
	gets(str1);
	gets(str2);
	gets(str3);
	gets(str4);
	char c1[3]={};
	char c3;
	int k;
	for(k=0;str1[k] && str2[k];k++)
	{
		if(str1[k]==str2[k] && (str1[k]>=65 && str1[k]<=71))
		{
			c1[0]=str1[k];
			break;
		}
	}
	for(int i=k+1;str1[i] && str2[i];i++)
	{
		if(str1[i]==str2[i] && (str1[i]>=65 && str1[i]<=78))
		{
			c1[1]=str1[i]-65+10;
			break;
		}
		if(str1[i]==str2[i] && (str1[i]>=48 && str1[i]<=57))
		{
			c1[1]=str1[i]-'0';
			break;
		}
	}
	int m=0;
	for(int i=0;str3[i] && str4[i];i++)
	{
		if(str3[i]==str4[i]	&& ((str3[i]>=97 && str3[i]<=122) || (str3[i]>=65 && str3[i]<=90)))
		{
			c3=str3[i];
			m=i;
			break;
		}
	}
	char *week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int n=c1[1];
	printf("%s %02d:%02d",week[c1[0]-65],n,m);
}










