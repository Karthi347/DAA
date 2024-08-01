#include <stdio.h>
#include<cstdlib>
typedef struct {
    int weight;
    int value;
    float ratio;
} Item;

int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    if (item1->ratio < item2->ratio) return 1;
    if (item1->ratio > item2->ratio) return -1;
    return 0;
}

float fractionalKnapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare);

    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity == 0) break;

        int weight = items[i].weight;
        int value = items[i].value;

        if (weight <= capacity) {
            totalValue += value;
            capacity -= weight;
        } else {
            totalValue += (value / (float)weight) * capacity;
            capacity = 0;
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];

    printf("Enter the Weight and Profit for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d weight and value: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    float maxValue = fractionalKnapsack(items, n, capacity);
    printf("Maximum value in the knapsack = %.2f\n", maxValue);

    return 0;
}

