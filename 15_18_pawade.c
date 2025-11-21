//Implementation of Trie and searching the key in trie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPHABET_SIZE 26
typedef struct trienode {
    struct trienode *children[ALPHABET_SIZE];
    int isEnd;   
}*tr;
tr getnode() {
    tr node = (tr)malloc(sizeof(struct trienode));
    node->isEnd = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}
void insert(tr root, char word[]) {
    tr curr = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (curr->children[index] == NULL)
            curr->children[index] = getnode();

        curr = curr->children[index];
    }
    curr->isEnd = 1;
}
int search(tr root, char word[]) {
    tr curr = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (curr->children[index] == NULL)
            return 0;

        curr = curr->children[index];
    }
    return curr != NULL && curr->isEnd;
}

int main() {
    tr root = getnode();
    char word[50];

    insert(root, "apple");
    insert(root, "app");
    insert(root, "bat");
    insert(root, "ball");

    printf("enter word to search: ");
    scanf("%s", word);

    if (search(root, word))
        printf("found\n");
    else
        printf("not found\n");

    return 0;
}
