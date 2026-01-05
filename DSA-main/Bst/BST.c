#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * LC;
    struct node * RC;
} Node, *BST;

void insert(BST * B, int value) {
    Node ** trav = (Node **) B;
    while(*trav != NULL && (*trav) -> data != value) {
        trav = (*trav) -> data > value ? &((*trav)->LC) : &((*trav)->RC);
     }
     if(*trav == NULL) {
        *trav = (BST) calloc (1 , sizeof(Node));
        (*trav) -> data = value;
     }
} 

void inorder(BST B) {
    if(B == NULL) return;
    inorder(B -> LC);
    printf("%d ", B -> data);
    inorder(B -> RC);
} 

void deleteTree(BST * B) {
    if(*B == NULL) return;
    deleteTree(&((*B) -> LC));
    deleteTree(&((*B) -> RC));
    free(*B);
    *B = NULL;
}

int main() {
    BST B = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);
    
    for(int i = 0; i < n; i++) {
        insert(&B, values[i]);
    }
    
    inorder(B);
    printf("\n");
    deleteTree(&B);
    
    

    return 0;
}


