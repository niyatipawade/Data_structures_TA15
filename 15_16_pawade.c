//Finding minimum and maximum data element from BST
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
}node;
node* insert(node* root, int val) {
    if (root == NULL) {
        node* newNode = malloc(sizeof(node));
        newNode->data = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
int findmin(node* root) {
    if (root == NULL) {
        printf("tree is empty\n");
        return -1;
    }
    node* curr = root;
    while (curr->left != NULL)
        curr = curr->left;

    return curr->data;
}
int findmax(node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return -1;
    }
    node* curr = root;
    while (curr->right != NULL)
        curr = curr->right;

    return curr->data;
}

int main() {
     node* root = NULL;

    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 35);

    printf("Minimum = %d\n", findmin(root));
    printf("Maximum = %d\n", findmax(root));

    return 0;
}
