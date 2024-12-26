#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *right;
    struct node *left;
}node;

node* createNode(int data);

int main()
{
    node *root;
    root = createNode(12);
    node *p1,*p2;
    p1 = createNode(10);
    p2 = createNode(15);

    root->left=p1;
    root->right = p2;

    /*
    Binary Tree::
            (12)
          /     \
        (10)    (15)
    */

    return 0;
}

//For creating Nodes
node* createNode(int data){
    node *new = (node*)malloc(sizeof(node));
    new->data=data;
    new->left=NULL;
    new->right =NULL;
    return new;
}