#include<stdio.h>
bool isprime(int n)
{
	if (n<=1)
	{
		return false;
	}
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
	int a,b,i;
	printf("Enter lower and upper limits: \n");
	scanf("%d %d",&a,&b);
	if(a<=0||b<=0||a>b)
	{
		printf("Limit values cannot be negative cannot be zero or negative");
	}
	else
	{
		printf("prime numbers between %d and %d are: \n",a,b);
		for(i=a;i<=b;i++)
		{
			if(isprime(i)==true)
			{
				printf("%d ",i);
			}
		}
	}
}
