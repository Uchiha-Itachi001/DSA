#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
} node;

node *createNode(int data);
int isBST(node *p, node **prev);
void inOrderTraversal(node *root);

node *searching(node *root, int key);
int main()
{
    node *root;
    root = createNode(12);
    node *p1, *p2, *p3, *p4;
    p1 = createNode(10);
    p2 = createNode(15);
    p3 = createNode(9);
    p4 = createNode(11);
    /*
    Binary Tree::
              (12)
           /       \
        (10)       (15)
      /   \
    (9)   (11)

    */
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("The In-order Traversal Of this Tree is: ");
    inOrderTraversal(root);
    printf("\n");

    node *prev = NULL;
    if (isBST(root, &prev)){ 
        printf("The tree is a BST\n");

        int key;
        ;
        printf("Enter the Element : ");
        scanf("%d", &key);
        node *ser = searching(root, key);
        if (ser == NULL){
            printf("element not preset");
        }
        else{
            printf("%d is present ", ser->data);
        }
    }
    else
    {
        printf("The tree is not a BST\n So searching Not valid");
    }

    return 0;
}
// For Searching the element
node *searching(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == key)
    {
        return root;
    }
    else if (key > root->data)
    {
        return searching(root->right, key);
    }
    else
    {
        return searching(root->left, key);
    }
}


// InOrder Traversal Function
void inOrderTraversal(node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to check if the tree is a BST
int isBST(node *p, node **prev)
{
    if (p != NULL)
    {
        if (!isBST(p->left, prev))
        {
            return 0;
        }
        if (*prev != NULL && p->data <= (*prev)->data)
        {
            return 0;
        }
        *prev = p;
        return isBST(p->right, prev);
    }
    return 1;
}

// For creating Nodes
node *createNode(int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

/*
::: OUTPUT ::::
The In-order Traversal Of this Tree is: 9 10 11 12 15
The tree is a BST
Enter the Element : 12
12 is present

*/