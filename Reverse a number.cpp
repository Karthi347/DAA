#include<stdio.h>
int revnum(int n)
{
	int rev=0,rem;
	while(n!=0)
	{
		rem=n%10;
		rev=rev*10+rem;
		n/=10;
	}
	return rev;
}
int main()
{
	int n;
	printf("Enter a number: \n");
	scanf("%d",&n);
	printf("Reverse of %d is %d",n,revnum(n));
}
