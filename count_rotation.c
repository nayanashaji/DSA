#include <stdio.h>
#include <stdlib.h>

int countRotations(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low <= high) {
        if (arr[low] <= arr[high])
            return low;

        int mid = (low + high) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;

        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
            return mid;

        if (arr[mid] >= arr[low])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements (circularly sorted): ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int rotations = countRotations(arr, n);
    printf("The array is rotated %d times.\n", rotations);

    free(arr);
    return 0;
}
