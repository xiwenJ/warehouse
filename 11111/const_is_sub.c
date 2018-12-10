#include<stdio.h>

const char *is_sub(const char *str1,const char *str2)
{
	if(str1==NULL || str2==NULL) return NULL;
	for(int i=0,j;str1[i];i++)
	{
		for(j=0;str2[j];j++)
		{
			if(str1[i+j]==str2[j])
			{
				continue;
			}
			break;
		}
		if(str2[j]=='\0')
		{
			return str1+i;
		}
	}
	return NULL;
}

int count_is_sub(const char*str1,const char*str2)
{
	int num=0;
	for(;*str1;str1++)
	{
		if(is_sub(str1,str2))
		{
			str1=is_sub(str1,str2);
			num++;
		}
	}
	return num;
}


int main()
{
	char str1[100]={};
	char str2[100]={};
	gets(str1);
	gets(str2);
	printf("%d",count_is_sub(str1,str2));
}












