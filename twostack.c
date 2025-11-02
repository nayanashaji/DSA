#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int arr[MAX];
int top1 = -1, top2 = MAX;

// Push to Stack1
void push1(int x) {
    if (top1 < top2 - 1) {
        arr[++top1] = x;
        printf("%d pushed to Stack1\n", x);
    } else {
        printf("Stack Overflow!\n");
    }
}

// Push to Stack2
void push2(int x) {
    if (top1 < top2 - 1) {
        arr[--top2] = x;
        printf("%d pushed to Stack2\n", x);
    } else {
        printf("Stack Overflow!\n");
    }
}

// Pop from Stack1
int pop1() {
    if (top1 >= 0) {
        return arr[top1--];
    } else {
        printf("Stack1 Underflow!\n");
        return -1;
    }
}

// Pop from Stack2
int pop2() {
    if (top2 < MAX) {
        return arr[top2++];
    } else {
        printf("Stack2 Underflow!\n");
        return -1;
    }
}

// Display stacks
void display() {
    int i;
    printf("Stack1: ");
    for (i = top1; i >= 0; i--)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Stack2: ");
    for (i = top2; i < MAX; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice, val, stackChoice;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stack number (1/2): ");
                scanf("%d", &stackChoice);
                printf("Enter value: ");
                scanf("%d", &val);
                if (stackChoice == 1)
                    push1(val);
                else
                    push2(val);
                break;

            case 2:
                printf("Enter stack number (1/2): ");
                scanf("%d", &stackChoice);
                if (stackChoice == 1)
                    printf("Popped: %d\n", pop1());
                else
                    printf("Popped: %d\n", pop2());
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
