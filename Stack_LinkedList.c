#include<stdio.h>

struct Node{        // Define the structure for a node in the linked list
    int data;       // Data of the node
    struct Node *next;      // Pointer to the next node
};

struct Node *top=0;         // Initialize the top/head of the stack to NULL

void push(int x){
    struct Node *newnode;       // Create a new node
    newnode=(struct Node*)malloc(sizeof(struct Node));      // Allocate memory for the new node
    newnode -> data=x;      // Set the data of the new node
    newnode -> next = top;      // Point the new node's next to the current top of the stack
    top= newnode;       // Update the top of the stack to the new node
}

//display the stack
void display(){
    struct Node *temp;
    if(top==0){
        printf("underflow\n");
    }
    else{
        temp=top;
        while(temp != 0){
            printf("%d\n",temp -> data);        // Print the data of the current node
            temp = temp ->next;     // Move to the next node
        }
    }
}

//peek the top element of the stack
void peek(){
    if(top == 0){
        printf("Stack is empty\n");
    }
    else{
        printf("Top element is : %d\n", top -> data);
    }
}

//pop the top element of the stack
void pop(){
    struct Node *temp;          // Create a temporary pointer to hold the node being popped
    if(top == 0){
        printf("stack underflow\n");
    }
    else{
        temp =top;
        printf("Popped data is : %d\n", temp -> data);
        top = top -> next;      // Update the top of the stack to the next node
        free(temp);     // Free the memory allocated for the popped node
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    display();
    return 0;
}
