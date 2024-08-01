#include <stdio.h>

void selectionSort(int array[], int size);

int main() {
    
	int size;
    printf("Enter size of the array: \n");
    scanf("%d",&size);
    printf("Enter %d elements for the array: \n",size);
    int array[size];
    for(int i=0;i<size;i++)
    {
    	scanf("%d",&array[i]);
	}
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    selectionSort(array, size);
    
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}

void selectionSort(int array[], int size) {
    int i, j, minIndex;
    for (i = 0; i < size-1; i++) {
        minIndex = i;
        for (j = i+1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        
        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

