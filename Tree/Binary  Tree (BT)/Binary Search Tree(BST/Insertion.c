#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *right;
    struct node *left;
} node;

node* createNode(int data);
int isBST(node* p, node** prev);
void inOrder(node* root);
void insertion(node *root,int key){
    node *prev = NULL;
    while (root!=NULL)
    {
        prev = root;
        if(root->data == key){
            printf("%d is already present in The BST\n\n",key); //BST do not contain Duplicate Elements
            return ;
        }
        else if(root->data >key){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    node *new = createNode(key);
    if(key < prev->data ){
        prev->left = new;
    }
    else{
        prev->left = new;
    }
    printf("\n%d is Successfully inserted in the BST\n\n",key);
}

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
   /
 (8) <----inserting
    */
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("The In-order Traversal Before Insertion :: \n");
    inOrder(root);
    printf("\n");
    
    insertion(root,8);

    printf("The In-order Traversal After Insertion ::\n");
    inOrder(root);

    return 0;
}

// InOrder Traversal Function
void inOrder(node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }

}

// For creating Nodes
node* createNode(int data) {
    node *new = (node*)malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

/*

:::OUTPUT::::

The In-order Traversal Before Insertion :: 
9 10 11 12 15

8 is Successfully inserted in the BST

The In-order Traversal After Insertion ::
8 9 10 11 12 15

*/