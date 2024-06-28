#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a node at the beginning of a linked list
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
    
    // Adjust pointers to insert the new node at the beginning
    newNode->next = head;
    head = newNode;
    
    printf("Inserted %d at the beginning\n", newData);
    
    return head;
}

// Function to delete a node from the beginning of a linked list
struct Node* deleteFromBeginning(struct Node *head) {
    // Check if the list is empty
    if (head == NULL) {
        printf("List is already empty. Cannot delete.\n");
        return NULL;
    }
    
    // Store the current head node
    struct Node *temp = head;
    
    // Move head pointer to the next node
    head = head->next;
    
    // Free the memory of the original head node
    free(temp);
    
    printf("Deleted node from the beginning\n");
    
    return head;
}

// Function to print the linked list
void printList(struct Node *head) {
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate insertion and deletion at the beginning
int main() {
    struct Node *head = NULL; // Initialize an empty linked list

    // Insert nodes at the beginning
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);
    printList(head);

    // Delete nodes from the beginning
    head = deleteFromBeginning(head);
    printList(head);
    
    head = deleteFromBeginning(head);
    printList(head);
    
    head = deleteFromBeginning(head);
    printList(head);
    
    // Trying to delete from an empty list
    head = deleteFromBeginning(head);
    
    return 0;
}
