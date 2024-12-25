#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
    int data;
    struct Queue *next;
}Queue;

Queue *front= NULL,*rear= NULL; // Defind Front and rear Globaly

void display(Queue *front);
int DeQueue();
void EnQueue(int val);


int main()
{
   //You can do this itarativly using loops,
    EnQueue(2);
    EnQueue(22);
    EnQueue(41);
    EnQueue(53);
    EnQueue(81);
    EnQueue(63);
    EnQueue(8);
  
    display(front);
    printf("\n");
    printf("The Deleted element is :%d \n", DeQueue());
    printf("The Deleted element is :%d \n", DeQueue());
    printf("The Deleted element is :%d \n", DeQueue());
    display(front);
    
    return 0;
}
void display(Queue *front){
    printf("Queue elements are printing : \n");
    while(front!=NULL){
        printf("%d ",front->data);
       front =  front->next ;
    }
}
int DeQueue(){
    Queue *new = front;
    int val = -1;
    if(new == NULL){
        printf("The Queue is Empty");
    }
    else{
        val = front->data;
        front = front->next;
        free(new);
    }
    return val;
}
void EnQueue(int val){
    Queue *new = (Queue*)malloc(sizeof(Queue));
    if(new == NULL){
        printf("The Queue is full");
    }
    else{
        new->data = val;
        new->next = NULL;
        if(front==NULL){            
            front=rear=new;
        }
        else{
            rear->next=new;
            rear = new;
        }
    }
}
/*
::: OUTPUT :::
Queue elements are printing : 
2 22 41 53 81 63 8
The Deleted element is :2
The Deleted element is :22
The Deleted element is :41
Queue elements are printing :
53 81 63 8 
*/