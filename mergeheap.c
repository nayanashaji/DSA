#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct HeapNode {
    struct Node* node;
};

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct HeapNode heap[], int i, int size) {
    int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < size && heap[l].node->data < heap[smallest].node->data) smallest = l;
    if (r < size && heap[r].node->data < heap[smallest].node->data) smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, smallest, size);
    }
}

struct Node* extractMin(struct HeapNode heap[], int* size) {
    if (*size == 0) return NULL;
    struct Node* root = heap[0].node;
    heap[0] = heap[*size - 1];
    (*size)--;
    minHeapify(heap, 0, *size);
    return root;
}

void insertHeap(struct HeapNode heap[], struct Node* node, int* size) {
    int i = (*size)++;
    heap[i].node = node;
    while (i && heap[(i - 1) / 2].node->data > heap[i].node->data) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

struct Node* mergeKSortedLists(struct Node* lists[], int K) {
    struct HeapNode heap[K];
    int size = 0;
    for (int i = 0; i < K; i++)
        if (lists[i]) insertHeap(heap, lists[i], &size);
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;
    while (size > 0) {
        struct Node* minNode = extractMin(heap, &size);
        tail->next = minNode;
        tail = tail->next;
        if (minNode->next)
            insertHeap(heap, minNode->next, &size);
    }
    return dummy.next;
}

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void display(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int K, n, val;
    printf("Enter number of lists: ");
    scanf("%d", &K);
    struct Node* lists[K];
    for (int i = 0; i < K; i++) {
        printf("Enter number of elements in list %d: ", i + 1);
        scanf("%d", &n);
        struct Node* head = NULL, *temp = NULL;
        for (int j = 0; j < n; j++) {
            scanf("%d", &val);
            struct Node* newnode = newNode(val);
            if (!head) head = temp = newnode;
            else {
                temp->next = newnode;
                temp = newnode;
            }
        }
        lists[i] = head;
    }
    struct Node* result = mergeKSortedLists(lists, K);
    printf("Merged Sorted List: ");
    display(result);
    return 0;
}