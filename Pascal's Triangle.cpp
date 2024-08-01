#include <stdio.h>

void printPascal(int n) {
    int arr[n][n];

    for (int line = 0; line < n; line++) {
    	for(int j=n-line;j>0;j--)
    	{
    		printf(" ");
		}
        for (int i = 0; i <= line; i++) {
            if (i == 0 || i == line) {
                arr[line][i] = 1;
            } else {
                arr[line][i] = arr[line - 1][i - 1] + arr[line - 1][i];
            }
            printf("%d ", arr[line][i]);
        }
        printf("\n");
    }
}

int main() {
    int n = 5; // Number of lines of Pascal's Triangle
    printPascal(n);
    return 0;
}

