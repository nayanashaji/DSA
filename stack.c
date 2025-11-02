#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Initialize
void initialize() {
    top = -1;
}

// Check if full
int isFull() {
    return top == MAX - 1;
}

// Check if empty
int isEmpty() {
    return top == -1;
}

// Push operation
void push(int item) {
    if (isFull()) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = item;
    printf("%d pushed to stack.\n", item);
}

// Pop operation
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}

// Peek operation
int peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack[top];
}

// Display
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int choice, item;
    initialize();

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if (item != -1)
                    printf("%d popped from stack.\n", item);
                break;
            case 3:
                item = peek();
                if (item != -1)
                    printf("Top element: %d\n", item);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
