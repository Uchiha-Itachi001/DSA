#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int Front;
    int Back;
    int size;
    int *arr;
} Queue;

int isFull(Queue *p);
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
    int x;
    for (int i = 0; i < p->size; i++){
        printf("Enter the element valu : ");
        scanf("%d",&x);
        EnQueue(p, x);
    }
    printf("The Queue Elements are : \n");
    Display(p);

    return 0;
}
int isFull(Queue *p)
{
    if (p->Back == p->size - 1)
        return 1;
    return 0;
}
void EnQueue(Queue *p, int n)
{
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
}