#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

int hasLoop(node* head);

int main()
{
    node *head,*first,*second,*third,*four,*five;
    head=(node*)malloc(sizeof(node));
    first=(node*)malloc(sizeof(node));
    second=(node*)malloc(sizeof(node));
    third=(node*)malloc(sizeof(node));
    four=(node*)malloc(sizeof(node));
    five=(node*)malloc(sizeof(node));

    head->data = 12;
    head->next = first;
    first->data =14;
    first->next = second;
    second->data = 20;
    second->next = third;
    third->data = 4;
    third->next = four;
    four->data = 8;
    four->next = five;
    five->data = 10;
    five->next = second;

    if(hasLoop(head)){
        printf("There is a loop in the linked list\n");
    }
    else{
        printf("There is no loop in the linked list");
        }

    return 0;
}
int hasLoop(node* head){
    node* slow = head;
    node *fast = head ;
    while(fast!= NULL && fast->next != NULL){
        
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow){
            return 1;
        }
    }
    return 0;
}
