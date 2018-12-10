#include<stdio.h>
#include<string.h>

int num(char *str)
{
	int n=0;
	for(int i=0;str[i];i++)
	{
		if(str[i]==' ')
		{
			n++;
		}
	}
	return n;
}

char *to (char *str)
{
	if(str==NULL) return NULL;
	int len=strlen(str);
	int end=num(str)*2+len;
	str[end]='\0';
	end--;
	for(int i=len-1;i>=0;i--)
	{	
		if(str[i]==' ')
		{
			str[end--]='%';
			str[end--]='%';
			str[end--]='%';
		}
		else str[end--]=str[i];
	}
	return str;
}

char *to2(char *str)
{
	if(str[0]>=97 && str[0]<=122)
	{
		str[0]=str[0]-32;
	}
	for(int i=1;str[i];i++)
	{
		if(str[i]>=65 && str[i]<=90)
		{
			str[i]=str[i]+32;
		}
	}
	return str;
}

char *to3(char* str)
{
	for(int i=1;str[i];i++)
	{
		if(str[i]>=97 && str[i]<=122)
		{
		if(str[i-1]>=97 && str[i-1]<=122)
		{
			continue;
		}
		if(str[i-1]>=65 && str[i-1]<=90)
		{
			continue;
		}
		str[i]=str[i]-32;

		}

	}
	return str;
}

int main()
{
	char str[50]={};
	gets(str);
	printf("%s",to3(to2(to(str))));
}





