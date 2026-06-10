#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is Full! Cannot enqueue %d\n", value);
    } else {
        if (front == -1) front = 0; // Set front if queue was empty
        rear++;
        queue[rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        front++;
        if (front > rear) { // Reset queue when empty
            front = -1;
            rear = -1;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
