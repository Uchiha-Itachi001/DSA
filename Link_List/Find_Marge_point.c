#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

void display(node* head);
int Marge_point(node* head1,node* head2);

int main()
{   
    node *head_1,*head_2;
    node *first_1,*second_1,*third_1,*first_2,*second_2,*third_2,*common1,*common2;
    head_1=(node*)malloc(sizeof(node));
    first_1=(node*)malloc(sizeof(node));
    second_1=(node*)malloc(sizeof(node));
    third_1=(node*)malloc(sizeof(node));

    head_2=(node*)malloc(sizeof(node));
    first_2=(node*)malloc(sizeof(node));
    second_2=(node*)malloc(sizeof(node));
    third_2=(node*)malloc(sizeof(node));

    common1=(node*)malloc(sizeof(node));
    common2=(node*)malloc(sizeof(node));

    head_1->data = 12;
    head_1->next = first_1;
    first_1->data =14;
    first_1->next = second_1;
    second_1->data = 20;
    second_1->next = third_1;
    third_1->data = 4;
    third_1->next = common1;

    head_2->data = 2;
    head_2->next = first_2;
    first_2->data =5;
    first_2->next = second_2;
    second_2->data = 90;
    second_2->next = third_2;
    third_2->data = 9;
    third_2->next = common1;
 
    common1->data = 8;
    common1->next = common2;
    common2->data = 10;
    common2->next = NULL;

    printf("The First Linked List is: ");
    display(head_1);
    printf("The Second Linked List is: ");
    display(head_2);

    printf("The Marge Point is: %d\n",Marge_point(head_1,head_2));
    
    return 0;
}
void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
  
}
int Marge_point(node* head1,node* head2){
    if(head1 == NULL || head2 == NULL){
        return NULL;
    }
    node *ptr1 = head1;
    node *ptr2 = head2;
    while(ptr1!=ptr2){
        ptr1 = (ptr1==NULL)?head2:ptr1->next;
        ptr2 = (ptr2==NULL)?head1:ptr2->next;
    }
    return ptr1->data;

    return 0;
}