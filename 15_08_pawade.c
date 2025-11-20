//Infix to prefix
#include <stdio.h>
#include <conio.h>
#include<string.h>
#define MAX 120
char stack[MAX];
int top = -1;
void push(char c) {
     top++;
    stack[top] = c;
}
char pop() {
    return stack[top--];
}
int isopr(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
int priority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}
void reverse(char str[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char infix[MAX], prefix[MAX];
    int j = 0;
      printf("enter infix expression: ");
    scanf("%s", infix);

    reverse(infix);
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (!isopr(c) && c != '(' && c != ')') {
            prefix[j++] = c;
        }
        else if (c == ')') {
            push(c);
        }
        else if (c == '(') {
            while (top != -1 && stack[top] != ')')
                prefix[j++] = pop();
            pop();
        }
        else {
            while (top != -1 && isopr(stack[top]) &&
                   priority(stack[top]) > priority(c)) {
                prefix[j++] = pop();
            }
            push(c);
        }
    }
    while (top != -1) {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';
    reverse(prefix);
    for(int i=0; prefix[i]!='\0'; i++)
    {
        printf("%c",prefix[i]);
    }

    return 0;
}
