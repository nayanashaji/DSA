#include <stdio.h>
#include <stdlib.h>

int firstOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            result = mid;      // possible first occurrence
            high = mid - 1;    // keep searching left
        } 
        else if (arr[mid] < key) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    return result;
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

    printf("Enter %d sorted elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    int index = firstOccurrence(arr, n, key);

    if (index == -1)
        printf("Element not found.\n");
    else
        printf("First occurrence of %d is at index %d.\n", key, index);

    free(arr);
    return 0;
}
