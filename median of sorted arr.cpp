#include <stdio.h>
#include <limits.h>
#include<math.h>
double findMedianSortedArrays(int nums1[], int size1, int nums2[], int size2) {
    if (size1 > size2) {
        // Ensure nums1 is the smaller array
        return findMedianSortedArrays(nums2, size2, nums1, size1);
    }

    int x = size1;
    int y = size2;
    int low = 0, high = x;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];
        
        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX) {
            if ((x + y) % 2 == 0) {
                return (double)(fmax(maxX, maxY) + fmin(minX, minY)) / 2.0;
            } else {
                return (double)fmax(maxX, maxY);
            }
        } else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    return -1; // If input arrays are not sorted or invalid
}

// Example usage
int main() {
    int nums1[] = {1, 3,4,5,6};
    int nums2[] = {2,3,8,9,10};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Median: %f\n", findMedianSortedArrays(nums1, size1, nums2, size2));
    return 0;
}

