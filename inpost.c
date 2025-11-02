#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char c) {
    stack[++top] = c;
}

// Pop
char pop() {
    return stack[top--];
}

// Peek
char peek() {
    return stack[top];
}

// Precedence function
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

// Infix to Postfix
void infixToPostfix(char exp[]) {
    char result[MAX];
    int i, k = 0;

    for (i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        // If operand → add to result
        if (isalnum(c)) {
            result[k++] = c;
        }
        // If '(' → push
        else if (c == '(') {
            push(c);
        }
        // If ')' → pop until '('
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                result[k++] = pop();
            }
            pop(); // remove '('
        }
        // Operator
        else {
            while (top != -1 && precedence(c) <= precedence(peek())) {
                result[k++] = pop();
            }
            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        result[k++] = pop();
    }
    result[k] = '\0';

    printf("Postfix Expression: %s\n", result);
}

int main() {
    char exp[MAX];
    printf("Enter Infix Expression: ");
    scanf("%s", exp);

    infixToPostfix(exp);
    return 0;
}
