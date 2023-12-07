#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

typedef struct {
    int top;
    int items[STACK_SIZE];
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == STACK_SIZE - 1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

int calculate(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
    }
    printf("Invalid operator\n");
    exit(1);
}

int evaluatePostfixExpression(FILE* file) {
    Stack stack;
    initialize(&stack);
    
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (isdigit(ch)) {
            push(&stack, ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result = calculate(operand1, operand2, ch);
            push(&stack, result);
        }
    }
    
    return pop(&stack);
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Failed to open input file\n");
        return 1;
    }
    
    int result = evaluatePostfixExpression(file);
    printf("Result: %d\n", result);
    
    fclose(file);
    
    return 0;
}
