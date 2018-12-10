#include<stdio.h>

int main()
{
	int N;
	scanf("%d",&N);
	int arr[N][N],val=1;
	arr[N/2][N/2]=N*N;
	for(int i=0;i<N/2;i++)
	{
		for(int j=i;j<N-1-i;j++)
		{
			arr[i][j]=val++;
		}
		for(int j=i;j<N-1-i;j++)
		{
			arr[j][N-1-i]=val++;
		}
		for(int j=N-1-i;j>i;j--)
		{
			arr[N-1-i][j]=val++;
		}
		for(int j=N-1-i;j>i;j--)
		{
			arr[j][i]=val++;
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%2d ",arr[i][j]);
		}
		printf("\n");
	}
}
