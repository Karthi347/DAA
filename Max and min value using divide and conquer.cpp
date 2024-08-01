#include <stdio.h>

void findMaxMin(int arr[], int low, int high, int *min, int *max) {
    if (low == high) {
        *min = arr[low];
        *max = arr[low];
    } else if (high == low + 1) {
        if (arr[low] < arr[high]) {
            *min = arr[low];
            *max = arr[high];
        } else {
            *min = arr[high];
            *max = arr[low];
        }
    } else {
        int mid = (low + high) / 2;
        int min1, max1, min2, max2;
        findMaxMin(arr, low, mid, &min1, &max1);
        findMaxMin(arr, mid + 1, high, &min2, &max2);

        *min = (min1 < min2) ? min1 : min2;
        *max = (max1 > max2) ? max1 : max2;
    }
}

int main() {
    int n,min,max;
    printf("Enter size of array: \n");
    scanf("%d",&n);
    printf("Enter %d elements for the array: \n",n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
    	scanf("%d",&arr[i]);
	}

    findMaxMin(arr, 0, n - 1, &min, &max);

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}

