#include<stdio.h>
int power(int n,int d)
{
	int res=1;
	for (int i=0;i<d;i++)
	{
		res*=n;
	}
	return res;
}
int main()
{
	int n,d,temp;
	printf("Enter number of digits: ");
	scanf("%d",&d);
	printf("\nEnter %d digit number: ",d);
	scanf("%d",&n);
	int arm=0,i;
	temp=n;
	while(n!=0)
	{
		int rem=n%10;
		n=n/10;
		arm+=power(rem,d);
	}
	if (arm==temp)
	{
		printf("\n%d is an Armstring number",temp);
	}
	else
	{
		printf("\n%d is not an Armstring number",temp);
	}
}
