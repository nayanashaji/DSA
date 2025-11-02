#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = x;
}

// Pop
int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0'); // convert char to int
        } else {
            int val1 = pop();
            int val2 = pop();
            switch (exp[i]) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
        }
    }
    return pop();
}

int main() {
    char exp[MAX];
    printf("Enter Postfix Expression: ");
    scanf("%s", exp);

    printf("Result = %d\n", evaluatePostfix(exp));
    return 0;
}
