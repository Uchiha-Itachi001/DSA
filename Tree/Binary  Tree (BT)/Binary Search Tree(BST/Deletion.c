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
node *searching(node *root, int key);
node* inorderPredecessor(node *root);
node* deletion(node *root,int key);

int main() {
    node *root;
    root = createNode(12);
    node *p1, *p2, *p3, *p4, *p5, *p6;
    p1 = createNode(10);
    p2 = createNode(15);

    p3 = createNode(5);
    p4 = createNode(11);

    p5 = createNode(4);
    p6 = createNode(7);
    /*
    Binary Tree::
              (12)
           /       \
        (10)       (15)
      /   \       
    (5)   (11)  
   /   \
 4)     (7)
    */
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p3->left = p5;
    p3->right = p6;

    printf("The In-order Traversal Before Deletion :: \n");
    inOrder(root);
    printf("\n");
    
    node *temp = deletion(root,12);

    /*---
    Chaking if the temp is NULL, means the element is not present 
    So we Donn't need To print the tree
    ----*/
    if(temp!= NULL){
    printf("The In-order Traversal After Deletion ::\n");
    inOrder(root);
    printf("\n");
    printf("The ROOT node Is :  %d",root->data);
}
    return 0;
}

node *searching(node *root, int key){
   while (root !=NULL){
        if(root->data== key){
            return root;
        }
        else if(key >root->data ){
            root = root->right;
        }
        else{
            root = root->left;
        }
   }
   return NULL;
   
}

node* inorderPredecessor(node *root){
    root = root->left;
    while(root->right !=NULL){
        root = root->right;
    }
    return root;
}

node* deletion(node *root,int key){
    node* find = searching(root,key );
    // It Chake that The element is Exist or not , if the element is exist the the deletion work.Otherwise it just return NULL;
    if (find != NULL){
        // BASE condition
        if (root == NULL) {
            return NULL;
        }
    
        if(key < root->data) {
            root->left = deletion(root->left, key);
        } 
        else if(key > root->data) {
            root->right = deletion(root->right, key);
        } 
        else{
            // Node with one children
            if (root->left == NULL) {
                    node *temp = root->right;
                    free(root);
                    return temp;
                } 
            else if (root->right == NULL) {
                    node *temp = root->left;
                    free(root);
                    return temp;
                }

            // Node with two children
            node *ipre = inorderPredecessor(root);
            root->data = ipre->data;
            root->left = deletion(root->left, ipre->data);
        }
        return root;
    }

    printf("The %d element is not Presrnt in the BST",key);
    return NULL;
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

::::OUTPUT:::

The In-order Traversal Before Deletion :: 
4 5 7 10 11 12 15
The In-order Traversal After Deletion ::
4 5 7 10 11 15
The ROOT node Is :  11

*/