#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int items[MAX];
    int top;
} Stack;

bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
int top(Stack *s);
void display(Stack* s);

int main() {
    Stack s;

    s.top = -1; 

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 1);
    push(&s, 7);
    display(&s);
    printf("Top element is: %d\n", peek(&s));
    printf("Popped element is: %d\n", pop(&s));
    display(&s);
    
    return 0;
}

bool isFull(Stack* s) {
    return s->top == MAX - 1;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (!isFull(s)) {
        s->items[s->top++] = value;
    } else {
        printf("Stack is full!\n");
    }
}

int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    } else {
        printf("Stack is empty!\n");
        return -1; 
    }
}

int peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    } else {
        printf("Stack is empty!\n");
        return -1; 
    }
}

void display(Stack* s) {
    if (!isEmpty(s)) {
        printf("Stack elements: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    } else {
        printf("Stack is empty!\n");
    }
}