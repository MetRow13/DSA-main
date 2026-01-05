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
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1; 
    }
    return s->items[(s->top)--];
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1; 
    }
    return s->items[s->top];
}

int top(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1; 
    }
    return s->items[s->top];
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}
