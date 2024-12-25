#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
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

int main()
{
    Queue *p;
    p = (Queue *)malloc(sizeof(Queue));
    printf("Enter the Size of the Queue : ");
    scanf("%d", &p->size);
    p->Front = -1;
    p->Back = -1;
    p->arr = (int *)malloc(p->size * sizeof(int));
  
    EnQueue(p,23);
    EnQueue(p,4);
    EnQueue(p,6);
    EnQueue(p,9);
    printf("The Queue Elements are : \n");
    Display(p);

    printf("The deleted element are : %d", DeQueue(p));
    printf("The deleted element are : %d", DeQueue(p));
    printf("The deleted element are : %d", DeQueue(p));
    
    return 0;
}

int isEmpty(Queue *p){
    if (p->Back == p->Front)
        return 1;
    return 0;
}
int isFull(Queue *p){
    if (p->Back == p->size - 1)
        return 1;
    return 0;
}
int DeQueue(Queue *p){
    if (!isEmpty(p)){   
        p->Front++;
        printf("\n");
        return p->arr[p->Front];
    }
    else{
        printf("The stack is Underflow\n");
    }
}
void EnQueue(Queue *p, int n){
    if (!isFull(p))
    {
        p->Back++;
        p->arr[p->Back] = n;
    }
    else{
        printf("The stack is Overflow\n");
    }
}
void Display(Queue *p){
    for(int i=0;i<p->size;i++){
        printf("%d ",p->arr[i]);
    }
    printf("\n");
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