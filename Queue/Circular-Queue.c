#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
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

int main(){

    Queue *p;
    p = (Queue *)malloc(sizeof(Queue));
    p->size =4;
    p->Front,p->Back = 0; // Initiali-zation = 0;
    p->arr = (int *)malloc(p->size * sizeof(int));

    EnQueue(p,23);
    EnQueue(p,4);
    EnQueue(p,6);
    EnQueue(p,9);

    printf("The deleted element are : %d", DeQueue(p));
    printf("The deleted element are : %d", DeQueue(p));
    printf("The deleted element are : %d", DeQueue(p));
    printf("The deleted element are : %d", DeQueue(p));

    printf("\n\n");

    EnQueue(p,48);
    EnQueue(p,64);
    EnQueue(p,23);    

    printf("\n\n");

    if(isEmpty(p)){ 
        printf("Queue is Empty\n No more element can be DnQueue");
    }
    if(isFull(p)){
        printf("Queue is Full\nNo more element can be EeQueue");
    }
    return 0;
}

int isEmpty(Queue *p){
    if (p->Back == p->Front)
        return 1;
    return 0;
}
int isFull(Queue *p){
    if ((p->Back+1)%p->size ==p->Front){
        return 1;
    }
    return 0;
}
int DeQueue(Queue *p){
    if (!isEmpty(p)){   
        printf("\n");
        p->Front = (p->Front +1)%p->size;
        return p->arr[p->Front];
    }
    else{
        printf("The stack is Underflow\n");
    }
}
void EnQueue(Queue *p, int n){
    if (!isFull(p))
    {
        p->Back=(p->Back +1)%p->size;
        p->arr[p->Back] = n;
        printf("Enqueue element :%d\n",n);
    }
    else{
        printf("The stack is Overflow\n");
    }
}

/*
::: OUTPUT :::

Enter the Size of the Queue : 4
The Queue Elements are :
23 4 6 9

The deleted element are : 23
The deleted element are : 4
The deleted element are : 6
*/