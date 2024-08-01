#include <stdio.h>
#include <string.h>

int main() {
    char s1[100];
    char s2[100];
    int i, j, k, f;

    printf("Enter a word: \n");
    scanf("%s", s1);

    i = 0;
    while (s1[i] != '\0') {
        i++;
    }
    printf("Length of the word is: %d\n", i);

    j = i - 1;
    k = 0;
    while (j > -1) {
        s2[k] = s1[j];
        j--;
        k++;
    }
    s2[k] = '\0';

    printf("Reversed string is: %s\n", s2);

    f = 0;
    for (i = 0; i < k; i++) {
        if (s1[i] != s2[i]) {
            f = 1;
            break;
        }
    }

    if (f == 1) {
        printf("Not palindrome\n");
    } else {
        printf("Palindrome\n");
    }

    return 0;
}

