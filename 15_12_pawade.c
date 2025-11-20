//Program on linked list : creation, insertion, deletion, reversing, merging, finding middle ,
//sorting, detecting loop in linked list, sum of data, printing odd-even data form SLL
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct lined_list {
    int data;
    struct Node* next;
}*ll;

ll  head = NULL;
ll getnode(int val) {
     ll new1= (ll)malloc(sizeof(struct lined_list));
     new1->data = val;
     new1->next = NULL;
     return new1;
}
void insertend(int value) {
    ll newNode = getnode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }
    ll temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}
void insertbegin(int value) {
    ll new1 = getnode(value);
    new1->next = head;
    head = new1;
}
void deletevalue(int value) {
    if (head == NULL) return;
    ll temp = head;
    if (temp->data == value) {
        head = temp->next;
        free(temp);
        return;
    }
    ll prev = NULL;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
}
void reverse() {
    ll prev = NULL;
    ll  curr = head;
    ll next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void findmiddle() {
    if(head == NULL) 
    return;

    ll slow = head;
    ll fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;
    }
    printf("middle = %d\n", slow->data);
}
void sortList() {
    if (head == NULL) return;

    ll i, j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
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
    ll temp = head;

    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    printf("sum = %d\n", sum);
}
void detectloop() {
    ll slow = head;
    ll fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;

        if (slow == fast) {
            printf("loop detected\n");
            return;
        }
    }

    printf("no loop\n");
}
void printoddeven() {
    ll temp = head;
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
ll merge(ll a, ll b) {
    if (a == NULL) return b;
    if (b == NULL) return a;
    ll  result = NULL;
    if (a->data < b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

void display() {
    ll temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
}
int main() {
    int choice, val;

    do {
        printf("enter choice\n1.insert begin\n2.insert end\n3.delete value\n4.reverse\n5.find middle\n6.sort\n7.detect loop\n8.sum of data\n9.print odd/even\n10.print list\n11.exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter value: ");
           scanf("%d", &val);
          insertbegin(val);
           break;
            case 2:
             printf("Enter value: ");
              scanf("%d", &val); 
              insertend(val); 
              break;
            case 3: 
            printf("Enter value: "); 
            scanf("%d", &val); 
            deletevalue(val); 
            break;
            case 4: reverse();
             break;
            case 5: findmiddle();
             break;
            case 6: sortList();
             break;
            case 7: detectloop(); 
            break;
            case 8: sumdata();
             break;
            case 9: printoddeven();
             break;
            case 10: display();
             break;
            
        }
    }while(choice<11);
    return 0;
}
