#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Maximum size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Enqueue function
void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is Full!\n");
        return;
    }
    if (front == -1) front = 0;  // Initialize front if first element is inserted
    rear = (rear + 1) % SIZE;  // Move rear forward in a circular manner
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue function
void dequeue() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    if (front == rear) {  // If only one element was in the queue, reset it
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;  // Move front forward in a circular manner
    }
}

// Driver code
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60); // This should show "Queue is Full!"
    
    dequeue();
    dequeue();
    enqueue(60);
    enqueue(70);

    return 0;
}

