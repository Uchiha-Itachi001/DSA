#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *right;
    struct node *left;
}node;

node* createNode(int data);
void InOrder(node*p);

//@ In Binary search Tree In-Order Traversal. The Elements are Print in Sorted Increasing Order

int main()
{
    node *root;
    root = createNode(12);
    node *p1,*p2,*p3,*p4;
    p1 = createNode(10);
    p2 = createNode(15);
    p3 = createNode(9);
    p4 = createNode(11);

    root->left=p1;
    root->right = p2;
    p1->left=p3;
    p1->right = p4;

    printf("The In-order Traversal Of this Tree is : :\n");
    InOrder(root);
    /*
    Binary Tree::
              (12)
           /       \
        (10)       (15)
      /   \       
    (9)   (11)  
    */

    return 0;
}

//InOrder Travertsal Funcion
void InOrder(node*p){
    if(p!=NULL){
        InOrder(p->left);
        printf("%d ",p->data);
        InOrder(p->right);
    }
}
//For creating Nodes
node* createNode(int data){
    node *new = (node*)malloc(sizeof(node));
    new->data=data;
    new->left=NULL;
    new->right =NULL;
    return new;
}
/*

:::OUTPUT:::

The In-order Traversal Of this Tree is : :
9 10 11 12 15 
*/