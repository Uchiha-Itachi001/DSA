#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Initialize the head and tail of the doubly linked list
struct Node* head = NULL;
struct Node* tail = NULL;

void addAtEnd(int value);
void addAtBeginning(int value);
void removeFromBeginning();
void removeFromEnd();
void display();

int main() {
    addAtEnd(10);
    addAtEnd(20);
    addAtEnd(30);
    addAtBeginning(5);
    display();

    removeFromBeginning();
    display();

    removeFromEnd();
    display();

    removeFromEnd();
    removeFromEnd();
    removeFromEnd(); 

    return 0;
}
// Function to add a node at the end of the list
void addAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail == NULL) { // If the list is empty
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    printf("Added %d at the end.\n", value);
}

// Function to add a node at the beginning of the list
void addAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head == NULL) { // If the list is empty
        head = tail = newNode;
    } else {
        head->prev = newNode;
        head = newNode;
    }
    printf("Added %d at the beginning.\n", value);
}

// Function to remove a node from the beginning
void removeFromBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to remove.\n");
        return;
    }
    struct Node* temp = head;
    printf("Removed %d from the beginning.\n", temp->data);
    head = head->next;

    if (head == NULL) { // If the list becomes empty
        tail = NULL;
    } else {
        head->prev = NULL;
    }
    free(temp);
}

// Function to remove a node from the end
void removeFromEnd() {
    if (tail == NULL) {
        printf("List is empty. Nothing to remove.\n");
        return;
    }
    struct Node* temp = tail;
    printf("Removed %d from the end.\n", temp->data);
    tail = tail->prev;

    if (tail == NULL) { // If the list becomes empty
        head = NULL;
    } else {
        tail->next = NULL;
    }
    free(temp);
}

// Function to display the doubly linked list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List contents: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
