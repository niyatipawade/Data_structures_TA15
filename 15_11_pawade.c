//Arithmetic expression evaluation using stack
#include <stdio.h>
#include <conio.h>
#define MAX 20
int val[MAX];   
char opr[MAX];     
int topval = -1, topop = -1;
void pushval(int v) {
     topval++;
    val[topval] = v;
}
int popval() {
    return val[topval--];
}
void pushop(char c) {
     topop++;
    opr[topop] = c;
}
char popop() {
    return opr[topop--];
}
int priority(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}
int applyop(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}
int isopr(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}


int main() {
    char expr[MAX];
    int i;

    printf("enter infix expression: ");
    scanf("%s", expr);

    for (i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        if (!isopr(c) && c != '(' && c != ')') {
            pushval(c - '0');   
        }
        else if (c == '(') {
            pushop(c);
        }
        else if (c == ')') {
            while (topop != -1 && opr[topop] != '(') {
                int val2 = popval();
                int val1 = popval();
                char op = popop();

                pushval(applyop(val1, val2, op));
            }
            popop(); 
        }

        else {
            while (topop != -1 && priority(opr[topop]) >= priority(c)) {
                  // (priority(opr[topop]) >= priority(c)) {

                int val2 = popval();
                int val1 = popval();
                char op = popop();

                pushval(applyop(val1, val2, op));
           // }
            pushop(c);
        }
    }
    while (topop != -1) {
        int val2 = popval();
        int val1 = popval();
        char op = popop();

        pushval(applyop(val1, val2, op));
    }

    printf("Result = %d\n", popval());

    return 0;
}
}
