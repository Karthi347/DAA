#include<stdio.h>
int main()
{
	int n,i,perf=0;
	printf("Enter a number: \n");
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		if(n%i==0)
		{
			perf+=i;
		}
	}
	if(n==perf)
	{
		printf("The given number is a perfect number");
	}
	else
	{
		printf("The given number is not a perfect number");
	}
}
