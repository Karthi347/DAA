#include<stdio.h>

bool prime(int n)
{
	for(int i=2;i<n/2;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int m;
	printf("Enter a number: \n");
	scanf("%d",&m);
	bool r=prime(m);
	if(r)
	{
		printf("%d is a prime number",m);
	}
	else
	{
		printf("%d is not a prime number",m);
	}
}
