#include<stdio.h>
int gcd(int a, int b)
{
	while(a!=b)
	{
		if(a>b)
		{
			a=a-b;
		}
		else
		{
			b=b-a;
		}
	}
	return a;
}

int main()
{
	int a,b,g;
	printf("Enter two numbers: \n");
	scanf("%d %d",&a,&b);
	g=gcd(a,b);
	if(g==1)
	{
		printf("No GCD exists");
	}
	else
	{
		printf("GCD of %d and %d is: %d",a,b,g);
	}
}
