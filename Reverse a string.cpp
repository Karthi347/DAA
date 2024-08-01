#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	printf("Enter a string: \n");
	scanf("%s",str);
	int size=strlen(str);
	printf("Reverse of %s is:\n",str);
	for(int i=size-1;i>=0;i--)
	{
		printf("%c",str[i]);
	}
}
