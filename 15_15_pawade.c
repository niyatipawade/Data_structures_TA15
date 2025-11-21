//Printing data in given range of BST
#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    int data;
    struct BST *left, *right;
}*bst;

bst getnode(int val)
{
bst newNode = malloc(sizeof(struct BST));
    newNode->data = val;
newNode->left = NULL;
newNode->right = NULL;
}
bst insert(bst root, int val) {
    
    bst newNode = getnode(val);

    if (!root) return newNode;

    bst curr = root;
    bst  parent = NULL;

    while (curr) {
        parent = curr;
        if (val < curr->data) curr = curr->left;
        else curr = curr->right;
    }

    if (val < parent->data) parent->left = newNode;
    else parent->right = newNode;

    return root;
}

void printrange(bst root, int L, int R) {
    bst stack[100];
    int top = -1;
    bst curr = root;

    while (curr || top != -1) {
        while (curr) {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top--];

        if (curr->data >= L && curr->data <= R)
            printf("%d ", curr->data);

        if (curr->data > R)
            break;

        curr = curr->right;
    }
}

int main() {
    bst root = NULL;

    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 35);

    int L, R;
    printf("Enter L R: ");
    scanf("%d %d", &L, &R);

    printf("Values in range: ");
    printrange(root, L, R);
}
