#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

//Traversal Function
void Traversal(node *head);
node* Insertion_In_Between(node* head,int pos); //To Insert Element At the any position Function

int main()
{   
    int n;
    printf("Enter the number of element : ");
    scanf("%d",&n);
    node *head,*temp,*new;
    head = (node*)malloc(sizeof(node));
    printf("Enter the 1 element : ");
    scanf("%d",&head->data);
    head->next = NULL;
    
    temp = head;
    for(int i=2;i<=n;i++){
        new = (node*)malloc(sizeof(node));
        printf("Enter the %d element : ",i);
        scanf("%d",&new->data);
        new->next = NULL;
        temp->next = new;
        temp= new;
    }

    temp = head;
    printf("The Link-list Elements are : \n");
    Traversal(temp); // LInk-List Traversal



    int pos;
    printf("Enter the position to insert element : ");
    scanf("%d",&pos);


    head = Insertion_In_Between(head,pos);
    printf("After Inserting element at the Any Position are : \n");
    Traversal(head); // LInk-List Traversal
    
    
    return 0;
}

node* Insertion_In_Between(node* head,int pos){
   
    int ele;
    printf("Enter the inserted Element : ");
    scanf("%d",&ele);

    node *new= (node*)malloc(sizeof(node));
    node* temp = head;
    for(int i=0;i!=pos-1;i++){
        temp = temp->next;
    }

    new->data = ele;
    new->next = temp->next;
    temp->next = new;
    return head;

}
void Traversal(node *head){
    node *temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/*
  ::: OUTPUT :::

Enter the number of element : 5
Enter the 1 element : 1
Enter the 2 element : 2
Enter the 3 element : 3
Enter the 4 element : 4
Enter the 5 element : 5
The Link-list Elements are :
1 2 3 4 5
Enter the position to insert element : 3 
Enter the inserted Element : 102
After Inserting element at the Any Position are :     
1 2 3 102 4 5
*/