#include<stdio.h>

#define Size 5
int Queue[Size];
int front = -1;
int rear = -1;

int isFull(){
    if(rear == Size-1){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(front == -1 && rear == -1){
        return 1;
    }
    return 0;
}

void enqueue(int x){
    if(isFull()){
        printf("Queue is Full.\n");
    }
    else if(isEmpty()){
        front = rear = 0;
        Queue[rear] = x;
    }
    else{
        rear++;
        Queue[rear]= x;
    }
}

void dequeue(){
    if(isEmpty()){
        printf("Queue is Empty.\n");
    }
    else if(front == rear){
        printf("Dequque : %d\n", Queue[front]);
        front = rear = -1;
    }
    else{
        printf("Dequque : %d\n", Queue[front]);
        front++;
    }
}

void peek(){
    if(isEmpty()){
        printf("Queue is Empty.\n");
    }
    else{
        printf("Peek : %d\n\n", Queue[front]);
    }
}

void display(){
    if(isEmpty()){
        printf("Queueue is Empty.\n");
    }
    else{
        printf("Queue Elemets are : \n");
        int i;
        for(i=front; i<rear+1; i++){
            printf("%d\n", Queue[i]);
        }
    }
}

int main(){
    int choose = -1, x;
    while(choose !=0){
        printf("\n Enqueue  2. Dequeue  3. Peek  4. Display  0. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choose);

        switch(choose){
            case 1:
            printf("Enter the elements to enqueue : ");
            scanf("%d", &x);
            enqueue(x);
            break;

            case 2:
            dequeue();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            case 0:
            break;
            default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}