#include<stdio.h>
int main()
{
	char inp[100];
	int n=0;
	printf("Enter a string: \n");
	scanf("%s",inp);
	while(inp[n]!='\0')
	{
		n+=1;
	}
	printf("Length of the string is: %d",n);
}
