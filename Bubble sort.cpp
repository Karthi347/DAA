#include <stdio.h>

void bubbleSort(int array[], int size);

int main() {
    int size;
    printf("Enter size of the array: \n");
    scanf("%d",&size);
    int array[size];
    printf("Enter %d elements for the array:\n");
    for(int i=0;i<size;i++)
    {
    	scanf("%d",&array[i]);
	}
    
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    bubbleSort(array, size);
    
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}

void bubbleSort(int array[], int size) {
    int i, j;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

