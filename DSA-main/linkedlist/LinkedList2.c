#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

typedef struct{
    Node  *head;
    int count; 
} List;

List* initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);


int main()  {

    List *list = initialize();

    printf("Inserts: ");
    insertFirst(list, 10);
    insertFirst(list, 3);
    insertFirst(list, 6);
    insertLast(list, 20);
    insertPos(list, 15, 1);
    display(list);

    printf("\nElement at index 1: %d\n", retrieve(list, 1));
    printf("Index of element 20: %d\n", locate(list, 20));

    printf("Delete start: ");
    deleteStart(list);
    display(list);
  
    printf("\nDelete last: ");
    deleteLast(list);
    display(list);

    printf("\nDelete position 0: ");
    deletePos(list, 0);
    display(list);

    int ret = retrieve(list, 0);
    if (ret == -1) {
        printf("\nList is empty\n");
    } else {
        printf("\nElement at index 0: %d\n", ret);
    } 

    int loc = locate(list, 10);
    if (loc == -1) {
        printf("Element 10 not found\n");
    } else {
        printf("Index of element 10: %d\n", loc);
    }

    printf("Emptying the list...\n");
    empty(list);
    display(list);

    return 0;
}

List* initialize() {
    List *list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->count = 0;
    return list;
}

void empty(List *list) {

    Node *current = list->head;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->count = 0;

} 

void insertFirst(List *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
} 

void insertLast(List *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->count++;
}

void insertPos(List *list, int data, int index) {
    if (index < 0 || index > list->count) {
        printf("Invalid index\n");
        return;
    }
    if (index == 0) {
        insertFirst(list, data);
        return;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node *temp = list->head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    list->count++;
} 

void deleteStart(List *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->count--;
}

void deleteLast(List *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
    } else {
        Node *temp = list->head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    list->count--;
}

void deletePos(List *list, int index) {
    if (index < 0 || index >= list->count) {
        printf("Invalid index\n");
        return;
    }
    if (index == 0) {
        deleteStart(list);
        return;
    }
    Node *temp = list->head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    list->count--;
}

int retrieve(List *list, int index) {
    if (index < 0 || index >= list->count) {
        printf("Invalid index\n");
        return -1;
    }
    Node *temp = list->head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->data;
}

int locate(List *list, int data) {
    Node *temp = list->head;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == data) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
    
}

void display(List *list) {
    Node *temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        if(temp -> next != NULL) {
            printf("-> ");
        }
        temp = temp->next;
    }
   
}
