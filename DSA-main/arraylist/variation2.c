#include <stdio.h>
#define MAX 10

typedef struct 
{
    int elem[MAX];
    int count;
} Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);

int main() {
    Etype List;
    EPtr List = &list;

    initialize(L);

    insertPos(L, 5, 0);
    insertPos(L, 10, 1);
    insertPos(L, 15, 2);
    display(L);
    makeNULL(L);
    display(L);

    return 0;

}

void initialize(EPtr L) {
    L->count = 10;

} 

void insertPos(EPtr L, int data, int position) {
    if (L->count == MAX) {
        printf("List is full\n");
        return;
    }
    if (position < 0 || position > L->count) {
        printf("Invalid position\n");
        return;
    }
    for (int i = L->count; i > position; i--) {
        L->elem[i] = L->elem[i - 1];
    }
    L->elem[position] = data;
    L->count++;
}



void display(EPtr L) {
    for (int i = 0; i < L -> count; i++) {
        printf("%d ", L -> elem[i]);
    }
    printf("\n");
}   


void makeNULL(EPtr L) {
    L->count = 0;
}
