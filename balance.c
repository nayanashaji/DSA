#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = c;
}

// Pop
char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

// Function to check matching brackets
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Balanced parentheses function
int isBalanced(char exp[]) {
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) return 0;
            char popped = pop();
            if (!isMatchingPair(popped, exp[i]))
                return 0;
        }
    }
    return (top == -1);
}

// Main
int main() {
    char exp[MAX];
    printf("Enter expression: ");
    scanf("%s", exp);

    if (isBalanced(exp))
        printf("Balanced Expression\n");
    else
        printf("Unbalanced Expression\n");

    return 0;
}
