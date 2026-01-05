#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

Queue *initialize()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(Queue *q)
{
    return q->front == NULL;
}

void enqueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
        return;

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q))
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
        return -1;

    Node *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return value;
}

int front(Queue *q)
{
    if (isEmpty(q))
        return -1;
    return q->front->data;
}

void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Empty\n");
        return;
    }

    Node *temp = q->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Queue *Q = initialize();

    enqueue(Q, 1);
    enqueue(Q, 3);
    enqueue(Q, 5);
    printf("After enqueue: ");
    display(Q);

    enqueue(Q, 4);
    printf("After enqueue 4: ");
    display(Q);

    printf("Front: %d\n", front(Q));

    printf("Dequeued: %d\n", dequeue(Q));
    printf("After dequeue: ");
    display(Q);

    while (!isEmpty(Q))
    {
        dequeue(Q);
    }
    printf("After dequeue all: ");
    display(Q);

    free(Q);
    return 0;
}