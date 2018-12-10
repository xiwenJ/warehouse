#include<stdio.h>
int main()
{
	char arr[255]={1};
	int cnt=1;
	for(int i=2;i<=100;i++)
	{
		int carry=0;
		for(int j=0;j<cnt;j++)
		{
			int result=arr[j]*i+carry;
			arr[j]=result%10;
			carry=result/10;
		}
		while(carry)
		{
			arr[cnt]=carry%10;
			cnt++;
			carry/=10;
		}
	}
	for(int i=cnt-1;i>=0;i--)
	{
		printf("%hhd",arr[i]);
	}
}
