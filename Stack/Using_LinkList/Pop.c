#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

int isEmpty(node* Top);
int isFull(node* Top);
void push(node** Top);
void display(node *top);
int pop(node** top);

int main()
{   
    node* Top = NULL;

    int x;
    printf("To Pop Elements \nYou Need To Push Element.....\n");
    printf("Enter the Number Of element You Want To Push : ");
    scanf("%d",&x);
    for(int i=1;i<=x;i++){
    push(&Top);
    }
    display(Top);
    int delete = pop(&Top);
    printf("Popped Element is : %d\n",delete);
    display(Top);

    return 0;
}
int isEmpty(node* Top){
    return (Top==NULL)?1:0; //Ternary operation
}

int isFull(node* Top){
    node *temp = (node*)malloc(sizeof(node));
    if(temp==NULL) return 1;
    else{
        free(temp); //Because it take memory Space
        return 0;
    }
}

void push(node** Top){
    if(isFull(*Top)){
         printf("Stack is full\n");
         return;
    }
    else{
        node *new = (node*)malloc(sizeof(node));
        int n;
        printf("Enter the element valu : ");
        scanf("%d",&n);
        new->data = n;
        new->next = *Top;
        *Top = new;
    }
}
void display(node *top){
    if(isEmpty(top)){
        printf("Stack is empty\n");
        return;
    }
    else{
        printf("The Stack Elements are : \n");
        while(top!=NULL){
            printf("%d ",top->data);
            top= top->next;
        }
        printf("\n");
    }
}
int pop(node** top){
    if(isEmpty(*top)){
        printf("Stack is UnderFlow\n");
        return -1;
    }
    node* temp = *top;
    int data = (*top)->data;
    *top = (*top)->next;
    free(temp);
    return data;
}


/*
:::: OUTPUT :::::
To Pop Elements 
You Need To Push Element.....
Enter the Number Of element You Want To Push : 5
Enter the element valu : 1
Enter the element valu : 2
Enter the element valu : 3
Enter the element valu : 4
Enter the element valu : 5
The Stack Elements are :
5 4 3 2 1
Popped Element is : 5
The Stack Elements are :
4 3 2 1

*/