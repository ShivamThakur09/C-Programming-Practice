#include<stdio.h>
#define N 10
int Queue[N];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(rear == N-1){
        printf("Queue is full\n");
    }
    if(front == -1 && rear == -1){
        front=rear=0;
        Queue[rear] = x;
    }
    else{
        rear++;
        Queue[rear] = x;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is Empty\n");
    }
    else if(front == rear){
        printf("Dequeue : %d\n", Queue[front]);
        front = rear = -1;
    }
    else{
        printf("Dequeue : %d\n", Queue[front]);
        front++;
    }
}

void peek(){
    if(front == -1 && rear == -1){
        printf("Queue is Empty.\n");
    }
    else{
        printf("Peek : %d\n", Queue[front]);
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Queue is empty.\n");
    }
    else{
        printf("Queue Elements :\n");
        for(int i=front; i<rear+1; i++){
            printf("%d\n",Queue[i]);
        }
    }
}

void main(){
   enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    dequeue();
    dequeue();
    dequeue();
    peek();
    display();
    enqueue(70);
    enqueue(80);
    enqueue(90);
    enqueue(100);
    dequeue();
    dequeue();
    peek();
    display();
}