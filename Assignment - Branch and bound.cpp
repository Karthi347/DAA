#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 4

int costMatrix[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

bool assigned[N] = {false};

int minCost(int costMatrix[N][N], int row) {
    int min = INT_MAX;
    int minIndex = -1;
    for (int j = 0; j < N; j++) {
        if (!assigned[j] && costMatrix[row][j] < min) {
            min = costMatrix[row][j];
            minIndex = j;
        }
    }
    return minIndex;
}

int branchAndBound(int costMatrix[N][N]) {
    int result = 0;
    for (int i = 0; i < N; i++) {
        int j = minCost(costMatrix, i);
        assigned[j] = true;
        result += costMatrix[i][j];
    }
    return result;
}

int main() {
    printf("Minimum cost: %d\n", branchAndBound(costMatrix));
    return 0;
}

