//Detecting parenthesis matching using stack
#include <stdio.h>
#include <conio.h>
#define MAX 20

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack is full\n");
        return;
    }
    top++;
    stack[top] = c;
}

char pop() {
    if (top == -1) {
        return '\0';  
    }
    return stack[top--];
}

int match(char left, char right) {
    return (left == '(' && right == ')') ||
           (left == '{' && right == '}') ||
           (left == '[' && right == ']');
}

int balance(char expr[]) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        }
      
        else if (c == ')' || c == '}' || c == ']') {
            char x = pop();

            if (!match(x, c)) {
                return 0;   
            }
        }
    }
    return top == -1;  
}

int main() {
    char exp[MAX];

    printf("Enter expression:\n");
     scanf("%s", exp);
    if (balance(exp))
        printf("parentheses are balanced.\n");
    else
        printf("parentheses are not balanced.\n");

    return 0;
}
