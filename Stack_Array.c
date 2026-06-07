#include<stdio.h>
#define Size 5

int Stack[Size];
int Top = -1;

void push(){
    int x;
    if(Top == Size-1){
        printf("Stack Overflow\n");
    }
    else{
        printf("Enter the element You want to push : ");
        scanf("%d",&x);
       
        Top++;
        Stack[Top] = x;
    }
}

void pop(){
    int item;
    if(Top == -1){
        printf("Stack Underflow.\n");
    }
    else{ 
        item = Stack[Top];
        Top--;
        printf("Popped element is : %d\n", item);
    }
}

void peek(){
    if(Top == -1){
        printf("Stack is Empty\n");
    }
    else{

        printf("Top element is : %d\n", Stack[Top]);
    }
}

void display(){
    if(Top == -1){
        printf("Stack is Empty. \n");
    }
    else{
        printf("The Stack is : \n");
        for(int i=Top; i>=0; i--){
            printf("%d\n", Stack[i]);
        }
    }
}

void main(){
    int choice;
    
    while(choice != 5) {
        printf("\n1. Push   2. Pop   3. Peek   4. Display   5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: peek();
            break;
            case 4: display();
            break;
            case 5: printf("Invalid Input. Please enter a valid choice.....\n");
            break;
        }
    }
}
