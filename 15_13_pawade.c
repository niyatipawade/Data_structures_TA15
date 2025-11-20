//Program on doubly linked list : creation, insertion, deletion, reversing, merging, finding middle ,
//sorting, detecting loop in linked list, sum of data, printing odd-even data form SLL
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

typedef struct doubly_ll {
    int data;
    struct Node* prev;
    struct Node* next;
}*dll;

dll head = NULL;

dll getnode(int value) {
    dll new1 = (dll)malloc(sizeof(struct doubly_ll));
    new1->data = value;
    new1->prev = NULL;
    new1->next = NULL;
    return new1;
}
void insertbegin(int value) {
    dll newNode = getnode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insertend(int value) {
    dll new1 = getnode(value);

    if (head == NULL) {
        head = new1;
        return;
    }

    dll temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new1;
    new1->prev = temp;
}
void deletevalue(int value) {
    if (head == NULL) return;

    dll temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) return;

    if (temp->prev != NULL)
    {
        temp=temp->prev;
        temp= temp->next;
    }
    else
        head = temp->next;

    if (temp->next != NULL){
        temp=temp->next;
        temp->prev = temp->prev;
    }

    free(temp);
}
void reverse() {
    dll curr = head, temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL)
        head = temp->prev;
}
void findmiddle() {
    if (head == NULL) return;

    dll slow = head, fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;
    }

    printf("middle = %d\n", slow->data);
}
void sortlist() {
    if (head == NULL) return;

    dll i, j;
    int temp;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void sumdata() {
    int sum = 0;
    dll temp = head;

    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }

    printf("sum = %d\n", sum);
}
void printoddeven() {
    dll temp = head;
    printf("odd: ");
    while (temp != NULL) {
        if (temp->data % 2 != 0)
            printf("%d ", temp->data);
        temp = temp->next;
    }

    temp = head;
    printf("\neven: ");
    while (temp != NULL) {
        if (temp->data % 2 == 0)
            printf("%d ", temp->data);
        temp = temp->next;
    }
}
void printforward() {
    dll temp = head;
    printf("forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void printbackward() {
    if (head == NULL) return;

    dll temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    printf("backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

int main() {
    int choice, val;

    do {
        printf("enter choice\n 1. Insert Begin\n 2. Insert End\n 3. Delete Value\n 4. Reverse\n 5. Find Middle\n 6. Sort\n 7. Sum of Data\n 8. Print Odd/Even\n 9. Print Forward\n 10. Print Backward\n 11. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Value: ");
             scanf("%d", &val);
              insertbegin(val);
               break;
            case 2: printf("Value: ");
             scanf("%d", &val); 
              insertend(val);
               break;
            case 3: printf("Value: ");
             scanf("%d", &val);
              deletevalue(val);
               break;
            case 4: reverse();
             break;
            case 5: findmiddle();
             break;
            case 6: sortlist();
             break;
            case 7: sumdata();
             break;
            case 8: printoddeven();
             break;
            case 9: printforward();
             break;
            case 10: printbackward();
             break;
          
        }
    } while (choice < 11);   
     return 0;
}
