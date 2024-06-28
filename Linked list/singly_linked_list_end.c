#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a node at the end of a linked list
struct Node* insertAtEnd(struct Node *head, int newData) {
    // Allocate memory for new node
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    
    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }
    
    // Assign data to the new node
    newNode->data = newData;
    newNode->next = NULL;
    
    // If the list is empty, make the new node as head
    if (head == NULL) {
        head = newNode;
        printf("Inserted %d at the end\n", newData);
        return head;
    }
    
    // Traverse the list to find the last node
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Attach the new node at the end
    temp->next = newNode;
    
    printf("Inserted %d at the end\n", newData);
    
    return head;
}

// Function to delete a node from the end of a linked list
struct Node* deleteFromEnd(struct Node *head) {
    // Check if the list is empty
    if (head == NULL) {
        printf("List is already empty. Cannot delete.\n");
        return NULL;
    }
    
    // If there is only one node, delete it and return NULL
    if (head->next == NULL) {
        printf("Deleted node from the end\n");
        free(head);
        return NULL;
    }
    
    // Traverse the list to find the second last node
    struct Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    // Free the memory of the last node
    free(temp->next);
    
    // Set the next of second last node to NULL
    temp->next = NULL;
    
    printf("Deleted node from the end\n");
    
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

// Main function to demonstrate insertion and deletion at the end
int main() {
    struct Node *head = NULL; // Initialize an empty linked list

    // Insert nodes at the end
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    printList(head);

    // Delete nodes from the end
    head = deleteFromEnd(head);
    printList(head);
    
    head = deleteFromEnd(head);
    printList(head);
    
    head = deleteFromEnd(head);
    printList(head);
    
    // Trying to delete from an empty list
    head = deleteFromEnd(head);
    
    return 0;
}
