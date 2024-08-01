#include<stdio.h>

int largest(int a[],int s)
{
	int l=a[0],i;
	for(i=0;i<s;i++)
	{
		if (a[i]>l)
		{
			l=a[i];
		}
	}
	return l;
}

int main()
{
	int s,i;
	printf("Enter the size of the array: \n");
	scanf("%d",&s);
	printf("Enter %d elements for the array: \n",s);
	int arr[s];
	for(i=0;i<s-1;i++)
	{
		scanf("%d ",&arr[i]);
	}
	printf("Largest element among the array is: %d",largest(arr,s));
}
