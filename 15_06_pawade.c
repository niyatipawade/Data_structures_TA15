//Decimal to binary
#include <conio.h>
#include <stdio.h>
#define MAX 32

int stack[MAX];
int top = -1;
void push(int val) {
    if (top == MAX - 1) {
        printf("stack is full\n");
    }
    else{
    top++;
    stack[top] = val;
    }
}
int pop() {
    if (top == -1) {
        printf("stack is empty\n");
        return -1;
    }
    return stack[top--];
}
int main() {
    int num;
     printf("Enter a decimal number: ");
    scanf("%d", &num);
      if (num == 0) {
        printf("Binary: 0\n");
        return 0;
    }
    int n = num;
    while (n > 0) {
        int bit = n % 2;   
        push(bit);         
        n = n / 2;
    }
      printf("Binary: ");
    while (top != -1) {
        printf("%d", pop());
    }

    return 0;
}
