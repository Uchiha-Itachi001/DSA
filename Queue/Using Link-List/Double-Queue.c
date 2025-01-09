#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Define the structure of the deque
struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Initialize the deque
void initDeque(struct Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

// Insert at the front of the deque
void insertFront(struct Deque* deque, int value) {
    struct Node* newNode = createNode(value);
    
    if (deque->front == NULL) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
    printf("%d inserted at front\n", value);
}

// Insert at the rear of the deque
void insertRear(struct Deque* deque, int value) {
    struct Node* newNode = createNode(value);
    
    if (deque->rear == NULL) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
    printf("%d inserted at rear\n", value);
}

// Delete from the front of the deque
void deleteFront(struct Deque* deque) {
    if (deque->front == NULL) {
        printf("Deque is empty\n");
        return;
    }
    
    struct Node* temp = deque->front;
    deque->front = deque->front->next;
    
    if (deque->front != NULL) {
        deque->front->prev = NULL;
    } else {
        deque->rear = NULL; // If the deque is now empty
    }
    
    printf("%d deleted from front\n", temp->data);
    free(temp);
}

// Delete from the rear of the deque
void deleteRear(struct Deque* deque) {
    if (deque->rear == NULL) {
        printf("Deque is empty\n");
        return;
    }
    
    struct Node* temp = deque->rear;
    deque->rear = deque->rear->prev;
    
    if (deque->rear != NULL) {
        deque->rear->next = NULL;
    } else {
        deque->front = NULL; // If the deque is now empty
    }
    
    printf("%d deleted from rear\n", temp->data);
    free(temp);
}

// Display the deque from front to rear
void displayDeque(struct Deque* deque) {
    if (deque->front == NULL) {
        printf("Deque is empty\n");
        return;
    }
    
    struct Node* temp = deque->front;
    printf("Deque contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the deque
int main() {
    struct Deque deque;
    initDeque(&deque);
    
    insertFront(&deque, 10);
    insertRear(&deque, 20);
    insertFront(&deque, 5);
    insertRear(&deque, 30);
    
    displayDeque(&deque);
    
    deleteFront(&deque);
    deleteRear(&deque);
    
    displayDeque(&deque);
    
    return 0;
}
