#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    char name[50];
    int category;
    struct Customer* next;
};

struct PriorityQueue {
    struct Customer* front;
};

struct Customer* createNode(char* name, int category) {
    struct Customer* newNode = (struct Customer*)malloc(sizeof(struct Customer));
    strcpy(newNode->name, name);
    newNode->category = category;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct PriorityQueue* pq, char* name, int category) {
    struct Customer* newNode = createNode(name, category);
    if (pq->front == NULL || category < pq->front->category) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        struct Customer* temp = pq->front;
        while (temp->next != NULL && temp->next->category <= category)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("%s added to queue.\n", name);
}

void dequeue(struct PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Customer* temp = pq->front;
    pq->front = pq->front->next;
    printf("Served: %s\n", temp->name);
    free(temp);
}

void display(struct PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Customer* temp = pq->front;
    printf("\nCurrent Queue:\n");
    while (temp != NULL) {
        printf("%s (Category %d)\n", temp->name, temp->category);
        temp = temp->next;
    }
}

int main() {
    struct PriorityQueue pq;
    pq.front = NULL;
    int choice, category;
    char name[50];

    while (1) {
        printf("\n--- PRIORITY QUEUE SYSTEM ---\n");
        printf("1. Enqueue Customer\n");
        printf("2. Dequeue Customer\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                scanf("%[^\n]", name);
                getchar();
                printf("Enter category (1-Differently Abled, 2-Senior Citizen, 3-Defence, 4-Ordinary): ");
                scanf("%d", &category);
                getchar();
                enqueue(&pq, name, category);
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                display(&pq);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}