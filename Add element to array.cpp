#include<stdio.h>
int main()
{
	int size;
	printf("Enter size of array:\n");
	scanf("%d",&size);
	int arr[100];
	printf("Enter array elements:\n");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter element to add:\n");
	int n,pos;
	scanf("%d",&n);
	printf("Enter position:\n");
	scanf("%d",&pos);
	pos-=1;
	for(int i=pos+1;i<size+2;i++)
	{
		arr[i]=arr[i+1];
		printf("%d ",arr[i]);
		
	}
}
