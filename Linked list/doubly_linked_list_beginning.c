#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to insert a node at the beginning of a doubly linked list
struct Node* insertAtBeginning(struct Node *head, int newData) {
    // Allocate memory for new node
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    
    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }
    
    // Assign data to the new node
    newNode->data = newData;
    
    // Adjust pointers for the new node
    newNode->prev = NULL;
    newNode->next = head;
    
    // If list is not empty, adjust the previous pointer of head
    if (head != NULL) {
        head->prev = newNode;
    }
    
    // Update head to point to the new node
    head = newNode;
    
    printf("Inserted %d at the beginning\n", newData);
    
    return head;
}

// Function to delete a node from the beginning of a doubly linked list
struct Node* deleteFromBeginning(struct Node *head) {
    // Check if the list is empty
    if (head == NULL) {
        printf("List is already empty. Cannot delete.\n");
        return NULL;
    }
    
    // Store the node to be deleted
    struct Node *temp = head;
    
    // Move head to the next node
    head = head->next;
    
    // If the new head is not NULL, update its prev pointer
    if (head != NULL) {
        head->prev = NULL;
    }
    
    // Free the memory of the original head node
    free(temp);
    
    printf("Deleted node from the beginning\n");
    
    return head;
}

// Function to print the doubly linked list from head to tail
void printList(struct Node *head) {
    struct Node *temp = head;
    printf("Linked List (head to tail): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to print the doubly linked list from tail to head (reverse)
void printReverseList(struct Node *head) {
    struct Node *temp = head;
    
    // Move to the last node
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    
    printf("Linked List (tail to head): ");
    
    // Traverse backward using the prev pointers
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Main function to demonstrate insertion and deletion at the beginning
int main() {
    struct Node *head = NULL; // Initialize an empty doubly linked list

    // Insert nodes at the beginning
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    printList(head);
    printReverseList(head);

    // Delete nodes from the beginning
    head = deleteFromBeginning(head);
    printList(head);
    printReverseList(head);
    
    head = deleteFromBeginning(head);
    printList(head);
    printReverseList(head);

    // Trying to delete from an empty list
    head = deleteFromBeginning(head);
    
    return 0;
}
