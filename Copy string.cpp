#include <stdio.h>
#include <string.h>

int main() {
    char str[100], res[100];

    printf("Enter a string: ");
    scanf("%s",str);

    strcpy(res,str);

    printf("Source string: %s\n", str);
    printf("Copied string: %s\n", res);

    return 0;
}

