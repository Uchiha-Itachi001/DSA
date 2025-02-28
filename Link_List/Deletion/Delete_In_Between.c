#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

//Traversal Function
void Traversal(node *head);
node* Deletion_In_Between(node* head,int n); //To Insert Element At the any position Function

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





    head = Deletion_In_Between(head,n);
    if(head == NULL){
        printf("You entered a in valid position......\nIt must be in 1 to %d\n try again",n);
    }
    else{
    printf("After deleting element at the Any Position are : \n");
    Traversal(head); // LInk-List Traversal
    }
    
    
    return 0;
}

node* Deletion_In_Between(node* head,int n){
   
    int pos;
    printf("Enter the position : ");
    scanf("%d",&pos);

   if(pos >n){
    return NULL;
   }

    node *new= (node*)malloc(sizeof(node));
    node* temp1 = head;
    node* temp2 = head->next;
    for(int i=1;i!=pos-1;i++){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    free(temp2);
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
Enter the position : 12
You entered a in valid position......
It must be in 1 to 5
 try again
*/