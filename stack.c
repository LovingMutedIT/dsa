#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100  // Maximum stack size

char stack[MAX];
int top = -1;

// Push function
void push(char ch) {
    if (top == MAX - 1) return;  // Stack overflow
    stack[++top] = ch;
}

// Pop function
char pop() {
    if (top == -1) return '\0';  // Stack underflow
    return stack[top--];
}

// Function to check if brackets match
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check if expression is valid
bool isValidExpression(char *expr) {
    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(expr[i]);  // Push opening brackets
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (top == -1 || !isMatchingPair(pop(), expr[i])) {
                return false;  // Unmatched closing bracket
            }
        }
    }
    return (top == -1);  // If stack is empty, it's valid
}

// Driver Code
int main() {
    char expr[MAX];

    printf("Enter expression: ");
    scanf("%s", expr);

    if (isValidExpression(expr)) {
        printf("Valid Expression\n");
    } else {
        printf("Invalid Expression\n");
    }

    return 0;
}

