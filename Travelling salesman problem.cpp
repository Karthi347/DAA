include <stdio.h>
#include <limits.h>

#define MAX 20
#define INF INT_MAX

int n;
int dist[MAX][MAX];
int memo[MAX][1 << MAX];

int tsp(int pos, int mask) {
    if (mask == ((1 << n) - 1)) {
        return dist[pos][0];
    }

    if (memo[pos][mask] != -1) {
        return memo[pos][mask];
    }

    int ans = INF;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(city, mask | (1 << city));
            if (newAns < ans) {
                ans = newAns;
            }
        }
    }

    return memo[pos][mask] = ans;
}

int main() {
    n = 4;
    int distInput[MAX][MAX] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = distInput[i][j];
        }
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < (1 << MAX); j++) {
            memo[i][j] = -1;
        }
    }

    printf("The minimum cost to visit all cities is %d\n", tsp(0, 1));

    return 0;
}

