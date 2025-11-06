#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapifyDown(int heap[], int i, int size) {
    int smallest = i, l = 2*i + 1, r = 2*i + 2;
    if (l < size && heap[l] < heap[smallest]) smallest = l;
    if (r < size && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, smallest, size);
    }
}

void heapifyUp(int heap[], int i) {
    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int maxActivityPoints(int A[], int n, int k) {
    int heap[k], size = 0;
    for (int i = 0; i < n; i++) {
        if (size < k) {
            heap[size++] = A[i];
            heapifyUp(heap, size - 1);
        } else if (A[i] > heap[0]) {
            heap[0] = A[i];
            heapifyDown(heap, 0, size);
        }
    }
    int sum = 0;
    for (int i = 0; i < size; i++) sum += heap[i];
    return sum;
}

int main() {
    int n, k;
    printf("Enter number of events: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter activity points for each event: ");
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    printf("Enter max number of events (k): ");
    scanf("%d", &k);
    printf("Maximum Activity Points = %d\n", maxActivityPoints(A, n, k));
    return 0;
}
