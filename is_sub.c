#include<stdio.h>


char* is_sub(const char* str1,const char* str2)
{
	if(NULL==str1 || NULL==str2) return NULL;
	for(int i=0,j;str1[i];i++)
	{
		for( j=0;str2[j];j++)
		{
			if(str1[i+j]==str2[j])
			{
				continue;
			}
			break;
		}
		if(str2[j]=='\0')
		return str2;
	}
	return NULL;
}

int main()
{
	char str1[100]={};
	char str2[100]={};
	gets(str1);
	gets(str2);
	printf("%s",is_sub(str1,str2)?"是":"不是");
}



