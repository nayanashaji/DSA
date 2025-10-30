#include <stdio.h>
#include <stdlib.h>

int searchRotatedArray(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        // Check if left half is sorted
        if (arr[low] <= arr[mid]) {
            if (key >= arr[low] && key < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Otherwise right half is sorted
        else {
            if (key > arr[mid] && key <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, key, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements (rotated sorted array): ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = searchRotatedArray(arr, n, key);

    if (result == -1)
        printf("Element not found.\n");
    else
        printf("Element found at index %d.\n", result);

    free(arr);
    return 0;
}
