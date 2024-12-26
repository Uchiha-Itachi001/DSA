#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *right;
    struct node *left;
}node;

node* createNode(int data);
void PreOrder(node*p);

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

    printf("The Preorder Traversal Of this Tree is : :\n");
    PreOrder(root);
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

//PreOrder Travertsal Funcion
void PreOrder(node*p){
    if(p!=NULL){
        printf("%d ",p->data);
        PreOrder(p->left);
        PreOrder(p->right);
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

The Preorder Traversal Of this Tree is : :
12 10 9 11 15 
*/