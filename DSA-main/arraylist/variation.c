#include <stdio.h>
#define MAX 10

typedef struct{
  int elem[MAX];
  int count;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

int main() {
    List L; 
    L = initialize(L);

    L = insertPos(L, 13, 0);
    L = insertPos(L, 7, 1);
    L = insertPos(L, 6, 2);
    L = insertPos(L, 2, 3);
    L = insertPos(L, 9, 4);
    printf("Insert position:\n");
    display(L);

    L = deletePos(L, 2);
    printf("After deleting position 2:\n");
    display(L);
    
    int pos = locate(L, 2);
    printf("Element %d found at position: %d\n", pos, pos);

    L = insertSorted(L, 5);
    printf("Insert sorted:\n");
    display(L);

  return 0; 
}  

List initialize(List L) {
    L.count = 0;
    return L;
} 

List insertPos(List L, int data, int position) {
    if (L.count >= MAX || position < 0 
                || position > L.count) {
        return L;
    }
    for (int i = L.count; i > position; i--) {
        L.elem[i] = L.elem[i - 1];
    }
    L.elem[position] = data;
    L.count++;
    return L;
} 

List deletePos(List L, int position) {
    if (position < 0 || position >= L.count) {
        return L;
    }
    for (int i = position; i < L.count - 1; i++) {
        L.elem[i] = L.elem[i + 1];
    }
    L.count--;
    return L;
} 

int locate(List L, int data) {
    for (int i = 0; i < L.count; i++) {
        if (L.elem[i] == data) {
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data) {
    for (int i = 0; i < L.count - 1; i++) {
        for (int j = i + 1; j < L.count; j++) {
            if (L.elem[i] > L.elem[j]) {
                int temp = L.elem[i];
                L.elem[i] = L.elem[j];
                L.elem[j] = temp;
            }
        }
    }
    return L;
}

void display(List L) {
    for (int i = 0; i < L.count; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}
    
        