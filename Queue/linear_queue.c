#include<stdio.h>
#define SIZE 5

void enQueue(int);
void deQueue();
void display();

int items[SIZE], front=-1, rear=-1;

int main() {
    deQueue(); //deQueue is not possible on empty queue

    //enQueue 5 elements
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);

    enQueue(6); //6th element cannot be added to because the queue is full

    display();

    deQueue(); //deQueue removes element entered first i.e. 1

    display(); //now we have only 4 elements

    return 0; 
}

void enQueue(int value) {
    if (rear==SIZE-1)
        printf("\nThe queue is full!");
    else {
        if (front==-1)
            front=0;
        rear++;
        items[rear]=value;
        printf("\nInserted -> %d",value);
    }
}

void deQueue() {
    if (front==-1)
        printf("\nThe queue is empty!");
    else{
        printf("\nDeleted: %d", items[front]);
        front++;
        if (front > rear)
            front=rear=-1;
    }
}

//Function to print the queue
void display() {
    if (rear==-1)
    printf("\nQueue is empty!");
    else {
        printf("\nQueue elements are:\n");
        for (int i=front; i<=rear; i++)
            printf("%d", items[i]);
    }
    printf("\n");
}