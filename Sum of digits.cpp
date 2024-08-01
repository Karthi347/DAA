#include<stdio.h>
int digsum(int n)
{
	int s=0;
	while(n!=0)
	{
		int rem=n%10;
		s+=rem;
		n=n/10;
	}
	return s;
}
int main()
{
	int n;
	printf("Enter a number:\n");
	scanf("%d",&n);
	printf("Sum of digits of %d is %d",n,digsum(n));
}
