//Creation of BST, tree traversal: inorder, preorder, postorders, BFS, DFS, mirror, children,
//sibling, parent of a node, GP of a node, uncle node
#include <stdio.h>
#include <stdlib.h>
typedef struct BST {
    int data;
    struct BST *left, *right;
}*bst;
bst getnode(int val) {
    bst new1 = (bst)malloc(sizeof(struct BST));
    new1->data = val;
    new1->left =NULL;
      new1->right = NULL;
    return new1;
}
bst insert(bst root, int val) {
    bst newNode = getnode(val);
    if (root == NULL)
     return newNode;

     bst curr = root;
    bst parent = NULL;

    while (curr != NULL) {
        parent = curr;
        if (val < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (val < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}
void inorder(bst root) {
    bst stack[100];
    int top = -1;
    bst curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}
void preorder(bst root) {
    if (root == NULL) 
    return;

    bst stack[100];
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        bst curr = stack[top--];
        printf("%d ", curr->data);

        if (curr->right)
            stack[++top] = curr->right;
        if (curr->left)
            stack[++top] = curr->left;
    }
}
void postorder(bst root) {
    if (root == NULL) 
    return;

    bst s1[100], s2[100];
    int t1 = -1, t2 = -1;

    s1[++t1] = root;

    while (t1 != -1) {
        bst temp = s1[t1--];
        s2[++t2] = temp;

        if (temp->left)  
        s1[++t1] = temp->left;

        if (temp->right) 
        s1[++t1] = temp->right;
    }

    while (t2 != -1)
        printf("%d ", s2[t2--]->data);
}


void bfs(bst root) {
    if (root == NULL) return;

    bst queue[100];
    int f = 0, r = 0;
    queue[r++] = root;

    while (f < r) {
        bst temp = queue[f++];
        printf("%d ", temp->data);

        if (temp->left)  queue[r++] = temp->left;
        if (temp->right) queue[r++] = temp->right;
    }
}
void mirror(bst root) {
    if (root == NULL) 
    return;

    bst stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        bst temp = stack[top--];
        bst t = temp->left;
        temp->left = temp->right;
        temp->right = t;
        if (temp->left) 
         stack[++top] = temp->left;

        if (temp->right) 
        stack[++top] = temp->right;
    }
}
bst findnode(bst root, int key, bst* parent) {
    *parent = NULL;
    bst curr = root;

    while (curr != NULL) {
        if (curr->data == key)
            return curr;

        *parent = curr;

        if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return NULL;
}
void children(bst root, int key) {
    bst parent = NULL;
    bst node = findnode(root, key, &parent);

    if (!node) { 
     printf("node not found\n"); 
     return;
 }

    printf("children of %d: ", key);
    if (node->left)  printf("%d ", node->left->data);
    if (node->right) printf("%d ", node->right->data);
    if (!node->left && !node->right) printf("no children");
    printf("\n");
}
void showparent(bst root, int key) {
    bst parent = NULL;
    bst node = findnode(root, key, &parent);

    if (!node) { 
     printf("node not found\n"); 
     return; 
    }

    if (parent)
        printf("parent = %d\n", parent->data);
    else
        printf("no parent (root node)\n");
}
void sibling(bst root, int key) {
    bst parent = NULL;
    bst node = findnode(root, key, &parent);

    if (!node || !parent) { 
     printf("no sibling\n");
      return; 
     }

    if (parent->left && parent->left->data == key && parent->right)
        printf("sibling = %d\n", parent->right->data);
    else if (parent->right && parent->right->data == key && parent->left)
        printf("sibling = %d\n", parent->left->data);
    else
        printf("no sibling\n");
}
void grandparent(bst root, int key) {
    bst parent = NULL, gp = NULL;
    bst node = findnode(root, key, &parent);

    if (!node || !parent) { 
     printf("no gp\n"); 
     return;
  }

    findnode(root, parent->data, &gp);
    if (gp)
        printf("grandparent = %d\n", gp->data);
    else
        printf("no gp\n");
}
void uncle(bst root, int key) {
    bst parent = NULL, gp = NULL;
    bst node = findnode(root, key, &parent);

    if (!node || !parent) { printf("no uncle\n"); return; }

    findnode(root, parent->data, &gp);
    if (!gp) { printf("no uncle\n"); return; }

    if (gp->left == parent && gp->right)
        printf("uncle = %d\n", gp->right->data);
    else if (gp->right == parent && gp->left)
        printf("uncle = %d\n", gp->left->data);
    else
        printf("no uncle\n");
}
int main() {
    bst root = NULL;
    int ch, val;

    do {
        printf("enter choice\n1.insert\n2.inorder\n3.preorder\n4.postorder\n5.bfs\n6.mirror\n7.children\n8.sibling\n9.parent\n10.grandparent\n11.uncle\n12.exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: printf("Value: ");
             scanf("%d", &val); 
             root = insert(root, val); 
             break;
            case 2: inorder(root); 
            printf("\n"); 
            break;
            case 3: preorder(root); 
            printf("\n"); 
            break;
            case 4: postorder(root); 
            printf("\n"); 
            break;
            case 5: bfs(root); 
            printf("\n"); 
            break;
            case 6: mirror(root); 
            printf("mirrored\n"); 
            break;
            case 7: printf("Node: "); 
            scanf("%d",&val); 
            children(root,val); 
            break;
            case 8: printf("Node: "); 
            scanf("%d",&val); 
            sibling(root,val); 
            break;
            case 9: printf("Node: "); 
            scanf("%d",&val); 
            showparent(root,val); 
            break;
            case 10: printf("Node: "); 
            scanf("%d",&val); 
            grandparent(root,val); 
            break;
            case 11: printf("Node: "); 
            scanf("%d",&val); 
            uncle(root,val); 
            break;
          
        }
    }while(ch < 12);
     return 0;
}
