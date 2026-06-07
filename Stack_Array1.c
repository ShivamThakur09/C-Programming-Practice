#include<stdio.h>
#define N 5

int Stack[N];
int top = -1;

int isFull(){
    return top == N-1;
}

int isEmpty(){
    return top == -1;
}

void push(int value){
    if(isFull()){
        printf("Stack is full. Cannot push %d\n\n.......", value);
        return;
    }
    else{
        top++;
        Stack[top] = value;
    }
}

void pop(){
    if(isEmpty()){
        printf("Stack is Underflow. There is nothing to pop.............\n\n");
        return;
    }
    else{
        printf("Stack item popped is %d\n\n", Stack[top--]);
    }
}

void peek(){
    if(isEmpty()){
        printf("Stack is Empty..............\n\n");
        return;
    }
    else{
        printf("Top element is :%d\n\n", Stack[top]);
    }
}

void display(){
    if(isEmpty()){
        printf("Stack is empty... Nothing to display.\n\n");
        return;
    }
    else{
        printf("Stack all element is:\n");
        for(int i=top; i>=0; i--){
            printf("%d. Index  ->  %d\n", i, Stack[i]);
        }
    }
    printf("\n");
}

int main(){
    int choice, value;

    while(choice !=5){
        printf("Use this : 1. Push  2. Pop  3. Peek  4. display  5. Exit\n");
        printf("Enter Your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter value you want to Push : ");
            scanf("%d", &value);
            printf("\n");
            push(value);
            break;

            case 2: pop();
            break;

            case 3: peek();
            break;

            case 4: display();
            break;

            case 5: printf("Invalid Input. Please enter a valid choice.....\n\n");
            break;


             default:printf("Please enter a valid choice.....\n\n");
             break;
        }
    }
    return 0;
}
