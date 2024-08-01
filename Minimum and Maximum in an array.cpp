#include <stdio.h>
#include <limits.h>

void find_min_max_sequences(int numbers[], int size) {
    if (size == 0) return;

    int min = INT_MAX, max = INT_MIN;
    int min_start = 0, min_end = 0, max_start = 0, max_end = 0;
    int current_min_start = 0, current_max_start = 0;

    for (int i = 0; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
            min_start = min_end = i;
        } else if (numbers[i] == min) {
            min_end = i;
        } else {
            current_min_start = i + 1;
        }

        if (numbers[i] > max) {
            max = numbers[i];
            max_start = max_end = i;
        } else if (numbers[i] == max) {
            max_end = i;
        } else {
            current_max_start = i + 1;
        }
    }

    printf("Minimum value sequence: ");
    for (int i = min_start; i <= min_end; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("Maximum value sequence: ");
    for (int i = max_start; i <= max_end; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main() {
    int numbers[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    find_min_max_sequences(numbers, size);

    return 0;
}

