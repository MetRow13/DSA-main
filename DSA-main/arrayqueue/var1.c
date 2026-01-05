#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int count;
}List;

typedef struct{
    List list;
    int front;
    int rear;
}Queue;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);

int main() {
    Queue* q = initialize();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 1);
    enqueue(q, 7);
    display(q);
    printf("Front element is: %d\n", front(q));
    printf("Dequeued element is: %d\n", dequeue(q));
    display(q);
    
    return 0;
} 

Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->list.count = 0;
    q->front = 0;
    q->rear = -1;
    return q;
}

bool isFull(Queue* q) {
    return q->list.count == MAX;
}

bool isEmpty(Queue* q) {
    return q->list.count == 0;
}

void enqueue(Queue* q, int value) {
    if (!isFull(q)) {
        q->rear = (q->rear + 1) % MAX;
        q->list.items[q->rear] = value;
        q->list.count++;
    } else {
        printf("Queue is full!\n");
    }
} 

int dequeue(Queue* q) {
    if (!isEmpty(q)) {
        int value = q->list.items[q->front];
        q->front = (q->front + 1) % MAX;
        q->list.count--;
        return value;
    } else {
        printf("Queue is empty!\n");
        return -1; 
    }
}

int front(Queue* q) {
    if (!isEmpty(q)) {
        return q->list.items[q->front];
    } else {
        printf("Queue is empty!\n");
        return -1; 
    }
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < q->list.count; i++) {
        int index = (q->front + i) % MAX;
        printf("%d ", q->list.items[index]);
    }
    printf("\n");
}
