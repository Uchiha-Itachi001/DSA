#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *right;
    struct node *left;
} node;

node* createNode(int data);
int isBST(node* p, node** prev);
void inOrderTraversal(node* root);

int main() {
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

    node* prev = NULL;
    if (isBST(root, &prev)) {
        printf("The tree is a BST\n");
    } else {
        printf("The tree is not a BST\n");
    }

    return 0;
}

// InOrder Traversal Function
void inOrderTraversal(node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to check if the tree is a BST
int isBST(node* p, node** prev) {
    if (p != NULL) {
        if (!isBST(p->left, prev)) {
            return 0;
        }
        if (*prev != NULL && p->data <= (*prev)->data) {
            return 0;
        }
        *prev = p;
        return isBST(p->right, prev);
    }
    return 1;
}

// For creating Nodes
node* createNode(int data) {
    node *new = (node*)malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}