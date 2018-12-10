#include<stdio.h>
#include<string.h>

char * release(char *str)
{	
	int i=0,k=0;
	int len=strlen(str);
	for(i=0;i<len/2;i++)
	{
		char temp=str[i];
		str[i]=str[len-1-i];
		str[len-1-i]=temp;
	}
	
	int num=0;
   	i=0;
   	while(num<len){
	
	for(i=k;str[i]!=' '&& (i<len);i++);
	for(int j=k;j<(i-k)/2+k;j++)
	{
		char temp=str[j];
		str[j]=str[i-1-(j-k)];
		str[i-1-(j-k)]=temp;
	}
	k=i+1;
	num=i;
	}
	return str;
}

int main()
{
	char str[80]={},str2[80]={},str3[80]={};
	gets(str);
	strcpy(str2,release(str));
	printf("%s",str2);

}







