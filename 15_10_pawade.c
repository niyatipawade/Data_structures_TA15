//Queue using linked list
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
ll front = NULL;
ll rear = NULL;

void enqueue(int val) {
    ll temp=getnode();
    temp->data = val;
    temp->next = NULL;

    if (front == NULL) {
        front = rear = temp; 
    } else {
        rear->next = temp;
        rear = temp;
    }
}
int dequeue() {
    if (front == NULL) {
        printf("queue is empty\n");
        return -1;
    }

    ll temp1 = front;
    int removed = temp1->data;

    front = front->next;

    if (front == NULL) {
        rear = NULL; 
    }

    free(temp1);
    return removed;
}
void display() {
    if (front == NULL) {
        printf("queue is empty\n");
        return;
    }

    ll temp = front;
    printf("queue: ");
    while (temp != NULL) {
        printf("%d \n", temp->data);
        temp = temp->next;
    }

}

int main() {
     int ch, val;
     do{
         printf("1.enqueue\n2.dequeue\n3.display\n");
         printf("enter your choice: ");
         scanf("%d", &ch);
         switch (ch) {
             case 1:
                 printf("enter value\n ");
                 scanf("%d", &val);
                 enqueue(val);
                 break;
 
             case 2:
                 val = dequeue();
                 if (val != -1)
                     printf("dequeued value: %d\n", val);
                 break;
 
             case 3:
                 display();
                 break;
         }
     } while (ch < 4);
    return 0;
}
