#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char item) {
if (top >= MAX_SIZE - 1) {
printf("Стек полон\n");
}
else {
top = top + 1;
stack[top] = item;
}
}

char pop() {
char item;

if (top < 0) {
printf("Стек пуст\n");
return '\0';
}
else {
item = stack[top];
top = top - 1;
return item;
}
}

int is_operator(char symbol) {
if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
return 1;
else
return 0;
}

int precedence(char symbol) {
if (symbol == '*' || symbol == '/')
return 2;
else if (symbol == '+' || symbol == '-')
return 1;
else
return 0;
}

void infix_to_postfix(char infix_expression[], char postfix_expression[]) {
int i, j;
char item;
char x;

push('(');
strcat(infix_expression, ")");
i = 0;
j = 0;
item = infix_expression[i];

while (item != '\0') {
if (item == '(') {
push(item);
}
else if (isdigit(item) || isalpha(item)) {
postfix_expression[j] = item;
j++;
}
else if (is_operator(item) == 1) {
x = pop();
while (is_operator(x) == 1 && precedence(x) >= precedence(item)) {
postfix_expression[j] = x;
j++;
x = pop();
}
push(x);
push(item);
}
else if (item == ')') {
x = pop();
while (x != '(') {
postfix_expression[j] = x;
j++;
x = pop();
}
}
else {
printf("Неправильное арифметическое выражение\n");
exit(1);
}
i++;
item = infix_expression[i];
}

if (top > 0) {
printf("Неправильное арифметическое выражение\n");
exit(1);
}

postfix_expression[j] = '\0';
}

int main() {
char infix[100], postfix[100];

printf("Введите инфиксное арифметическое выражение: ");
fgets(infix, sizeof(infix), stdin);

infix_to_postfix(infix, postfix);

printf("Постфиксное арифметическое выражение: %s\n", postfix);

return 0;
}

