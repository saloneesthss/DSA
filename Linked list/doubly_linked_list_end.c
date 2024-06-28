#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to insert a node at the end of a doubly linked list
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
    
    // If list is empty, make the new node as head
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        // Traverse the list to find the last node
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        // Attach the new node at the end
        temp->next = newNode;
        newNode->prev = temp;
    }
    
    printf("Inserted %d at the end\n", newData);
    
    return head;
}

// Function to delete a node from the end of a doubly linked list
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
    
    // Traverse the list to find the last node
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Adjust pointers to remove the last node
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    }
    
    // Free the memory of the last node
    free(temp);
    
    printf("Deleted node from the end\n");
    
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

// Main function to demonstrate insertion and deletion at the end
int main() {
    struct Node *head = NULL; // Initialize an empty doubly linked list

    // Insert nodes at the end
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    printList(head);
    printReverseList(head);

    // Delete nodes from the end
    head = deleteFromEnd(head);
    printList(head);
    printReverseList(head);
    
    head = deleteFromEnd(head);
    printList(head);
    printReverseList(head);
        
    // Trying to delete from an empty list
    head = deleteFromEnd(head);
    
    return 0;
}
