#include <stdio.h>
#include <stdlib.h>

int binomialCoeff(int n, int k) {
    int** C = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        C[i] = (int*)malloc((k + 1) * sizeof(int));
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= (i < k ? i : k); j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }

    int result = C[n][k];

    for (int i = 0; i <= n; i++) {
        free(C[i]);
    }
    free(C);

    return result;
}

int main() {
    int n = 5;
    int k = 2;
    printf("C(%d, %d) = %d\n", n, k, binomialCoeff(n, k));
    return 0;
}

