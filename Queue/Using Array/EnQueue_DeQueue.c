#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int front;
    int rear;
    int size;
    int *arr;
} queue;

int isEmpty(queue *q);
int isFull(queue *q);
void endq(queue *q);
int deq(queue *q);
void display(queue *q, int x);

int main()
{
    queue *q;
    q = (queue *)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    printf("Enter the size of the Queue : ");
    scanf("%d", &q->size);
    q->arr = (int *)malloc(q->size * sizeof(int));
    int x;
    printf("Enter the the number of element you Want[<=%d] : ", q->size);
    scanf("%d", &x);
    if (x <= q->size)
    {

        for (int i = 0; i < x; i++)
        {
            endq(q);
        }
    }
    else
    {
        printf("Invalid input ");
    }

    display(q, x);

    int delete;
    printf("Enter the number of element you want to delete[<=%d] : ", x);
    scanf("%d", &delete);
    if (x >= delete)
    {
        for (int i = 0; i < delete; i++)
        {
            printf("The Deleted Element is : %d\n", deq(q));
        }
        if (isEmpty(q))
        {
            printf("Queue is Empty");
        }
        else{

        display(q, x);
        }
    }
    else
    {
        printf("Invalid input ");
    }

    return 0;
}

int isEmpty(queue *q){
    return (q->front == q->rear) ? 1 : 0;
}

int isFull(queue *q){
    return (q->rear == q->size - 1) ? 1 : 0;
}

void endq(queue *q){
    if (!isFull(q))
    {
        q->rear++;
        printf("Enter the inseted value : ");
        scanf("%d", &q->arr[q->rear]);
        printf("end-queue successfull \n");
    }
    else
    {
        printf("Queue is full \n");
    }
}

int deq(queue *q){
    if (!isEmpty(q))
    {
        return q->arr[++q->front];
    }
    else
    {
        printf("Queue is Empty \n");
    }
}

void display(queue *q, int x){
    printf("Queue Display :\n");
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

/*
::::::OUTPUT:::::
Enter the size of the Queue : 3
Enter the the number of element you Want[<=3] : 3
Enter the inseted value : 1
end-queue successfull 
Enter the inseted value : 23
end-queue successfull 
Enter the inseted value : 3
end-queue successfull 
Queue Display :
1 23 3
Enter the number of element you want to delete[<=3] : 3
The Deleted Element is : 1
The Deleted Element is : 23
The Deleted Element is : 3
Queue is Empty
*/