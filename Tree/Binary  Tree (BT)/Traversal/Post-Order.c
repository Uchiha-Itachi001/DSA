
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *right;
    struct node *left;
}node;

node* createNode(int data);
void PostOrder(node*p);

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

    printf("The Postorder Traversal Of this Tree is : :\n");
    PostOrder(root);
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

//PostOrder Travertsal Funcion
void PostOrder(node*p){
    if(p!=NULL){
        PostOrder(p->left);
        PostOrder(p->right);
        printf("%d ",p->data);
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

The Postorder Traversal Of this Tree is : :
9 11 10 15 12
*/