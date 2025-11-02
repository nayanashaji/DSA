#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Stack1 operations
void push1(int x) { stack1[++top1] = x; }
int pop1() { return stack1[top1--]; }
int peek1() { return stack1[top1]; }
int isEmpty1() { return top1 == -1; }

// Stack2 operations
void push2(int x) { stack2[++top2] = x; }
int pop2() { return stack2[top2--]; }
int peek2() { return stack2[top2]; }
int isEmpty2() { return top2 == -1; }

// Sort stack1 using stack2
void sortStack() {
    while (!isEmpty1()) {
        int temp = pop1();
        while (!isEmpty2() && peek2() > temp) {
            push1(pop2());
        }
        push2(temp);
    }
    // Transfer sorted elements back to stack1
    while (!isEmpty2()) {
        push1(pop2());
    }
}

// Display
void display() {
    if (isEmpty1()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Sorted Stack: ");
    for (int i = 0; i <= top1; i++)
        printf("%d ", stack1[i]);
    printf("\n");
}

int main() {
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push1(val);
    }

    sortStack();
    display();

    return 0;
}
