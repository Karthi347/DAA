#include <stdio.h>

void containerLoader(int containers[], int n, int maxWeight) {
    int currentWeight = 0;

    printf("Containers loaded: ");
    for (int i = 0; i < n; i++) {
        if (currentWeight + containers[i] <= maxWeight) {
            currentWeight += containers[i];
            printf("%d ", containers[i]);
        }
    }
    printf("\nTotal weight: %d\n", currentWeight);
}

int main() {
    int containers[] = {10, 20, 30, 40, 50};
    int n = sizeof(containers) / sizeof(containers[0]);
    int maxWeight = 100;

    containerLoader(containers, n, maxWeight);

    return 0;
}

