#include<stdio.h>
int main()
{
	int n,i,j;
	printf("Enter number of rows: \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=n-i;j>0;j--)
		{
			printf(" ");
		}
		int t=1;
		for(j=0;j<=i;j++)
		{
			printf("%d ",t);
			t++;
		}
		printf("\n");
	}
}
