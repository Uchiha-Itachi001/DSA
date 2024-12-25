#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int Front;
    int Back;
    int size;
    int *arr;
} Queue;

int isEmpty(Queue *p);
int isFull(Queue *p);
int DeQueue(Queue *p);
void EnQueue(Queue *p, int n);
void Display(Queue *p);

int main() {
    Queue *p;
    p = (Queue *)malloc(sizeof(Queue));
    p->size = 4;
    p->Front = p->Back = 0; // Initialization = 0;
    p->arr = (int *)malloc(p->size * sizeof(int));

    EnQueue(p, 23);
    EnQueue(p, 4);
    EnQueue(p, 6);
    EnQueue(p, 9);

    printf("The deleted element is: %d\n", DeQueue(p));
    printf("The deleted element is: %d\n", DeQueue(p));
    printf("The deleted element is: %d\n", DeQueue(p));
    printf("The deleted element is: %d\n", DeQueue(p));

    printf("\n");

    EnQueue(p, 48);
    EnQueue(p, 64);
    EnQueue(p, 23);

    printf("\n");

    if (isEmpty(p)) {
        printf("Queue is Empty\nNo more elements can be DeQueued\n");
    }
    if (isFull(p)) {
        printf("Queue is Full\nNo more elements can be EnQueued\n");
    }

    Display(p);

    free(p->arr);
    free(p);

    return 0;
}

int isEmpty(Queue *p) {
    return p->Back == p->Front;
}

int isFull(Queue *p) {
    return (p->Back + 1) % p->size == p->Front;
}

int DeQueue(Queue *p) {
    if (!isEmpty(p)) {
        p->Front = (p->Front + 1) % p->size;
        return p->arr[p->Front];
    } else {
        printf("The queue is Underflow\n");
        return -1; // Return an invalid value to indicate underflow
    }
}

void EnQueue(Queue *p, int n) {
    if (!isFull(p)) {
        p->Back = (p->Back + 1) % p->size;
        p->arr[p->Back] = n;
        printf("Enqueued element: %d\n", n);
    } else {
        printf("The queue is Overflow\n");
    }
}

void Display(Queue *p) {
    if (isEmpty(p)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    int i = (p->Front + 1) % p->size;
    while (i != (p->Back + 1) % p->size) {
        printf("%d ", p->arr[i]);
        i = (i + 1) % p->size;
    }
    printf("\n");
}

/*
:::OUTPUT:::
Enqueued element: 23
Enqueued element: 4
Enqueued element: 6
The queue is Overflow
The deleted element is: 23
The deleted element is: 4
The deleted element is: 6
The queue is Underflow
The deleted element is: -1

Enqueued element: 48
Enqueued element: 64
Enqueued element: 23

Queue is Full
No more elements can be EnQueued
Queue elements are: 48 64 23 
*/