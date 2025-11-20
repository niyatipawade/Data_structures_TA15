//Stack using linked list
#include <stdio.h>
#include <conio.h>
typedef struct linked_list {
    int data;
    struct linked_list* next;
}*ll;
ll getnode()
{
     ll new1;
     new1=(ll)malloc(sizeof(struct linked_list));
     new1->next=NULL;
     return new1;
}
ll top = NULL;
void push(int value) {
    ll temp=getnode();
    temp->data=value;

    if (!temp) {
        printf("stack is full\n");
        return;
    }
    temp->next = top;
    top = temp;
}
int pop() {
    if (top == NULL) {
        printf("stack is empty\n");
        return -1;
    }

    ll temp = top;
    int pop1 = temp->data;

    top = top->next;
    free(temp);

    return pop1;
}

void display() {
    if (top == NULL) {
        printf("stack is empty\n");
        return;
    }

    ll temp = top;
    printf("stack elements: ");
    while (temp != NULL) {
        printf("%d \n", temp->data);
        temp = temp->next;
    }
    
}

int main() {
    int ch, val;

    do{
        printf("enter choice\n1. Push\n2. Pop\n3. display\n4.exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value\n ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                val = pop();
                if (val != -1)
                    printf("Popped value: %d\n", val);
                break;

            case 3:
                display();
                break;
        }
    }while(ch<4);

    return 0;
}
