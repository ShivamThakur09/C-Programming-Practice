#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct Q {
    int R, F;
    int data[MAX];
} Q;

// Function Prototypes
void create(Q *);
void enqueue(Q *, int);           // Insert Rear
void dqinsert_front(Q *, int);    // Insert Front (Added)
int dequeue(Q *);                 // Delete Front
int dqdelete_rear(Q *);           // Delete Rear
void Print(Q *);

int main() {
    Q P;
    int x, n, m, a;

    create(&P);

    while (1) {
        printf("\n--- DEQUE OPERATIONS ---\n");
        printf("1. ENQUEUE (Insert Rear)\n");
        printf("2. DQINSERT_FRONT (Insert Front)\n");
        printf("3. DEQUEUE (Delete Front)\n");
        printf("4. DQDELETE_REAR (Delete Rear)\n");
        printf("5. PRINT QUEUE\n");
        printf("6. EXIT\n");
        printf("Enter Your Choice: ");
        
        if (scanf("%d", &n) != 1) { // Prevent infinite loops on non-integer input
            printf("Invalid input. Exiting.\n");
            break;
        }

        if (n == 6) {
            printf("Exiting program...\n");
            break;
        }

        switch (n) {
            case 1:
                printf("Enter the value to insert at rear: ");
                scanf("%d", &x);
                enqueue(&P, x);
                break;
            case 2:
                printf("Enter the value to insert at front: ");
                scanf("%d", &x);
                dqinsert_front(&P, x);
                break;
            case 3:
                m = dequeue(&P);
                if (m != -999) { 
                    printf("Deleted element from front = %d\n", m);
                }
                break;
            case 4:
                a = dqdelete_rear(&P);
                if (a != -999) {
                    printf("Deleted element from rear = %d\n", a);
                }
                break;
            case 5:
                Print(&P);
                break;
            default:
                printf("Invalid Choice! Please enter a number between 1 and 6.\n");
                break;
        }
    }
    return 0;
}

// --- Queue Functions ---

void create(Q *P) {
    P->R = -1;
    P->F = -1;
}

void enqueue(Q *P, int x) {
    if (P->R == MAX - 1) {
        printf("Queue is FULL at the rear (Overflow)!\n");
        return;
    }
    
    // If inserting the first element
    if (P->F == -1) {
        P->R = 0;
        P->F = 0;
        P->data[P->R] = x;
    } else {
        P->R = P->R + 1;
        P->data[P->R] = x;
    }
    printf("%d enqueued at rear successfully.\n", x);
}

// THE MISSING OPERATION: Insert Front
void dqinsert_front(Q *P, int x) {
    // If F is 0, we can't move backward unless we use a Circular Deque
    if (P->F == 0) {
        printf("Front is full (Overflow)! Cannot insert at the front right now.\n");
        return;
    }
    
    // If inserting the first element
    if (P->F == -1) {
        P->F = 0;
        P->R = 0;
    } else {
        P->F = P->F - 1; // Move front pointer backward
    }
    
    P->data[P->F] = x;
    printf("%d inserted at front successfully.\n", x);
}

int dequeue(Q *P) {
    int x;

    // Check for Underflow
    if (P->F == -1) {
        printf("Queue is EMPTY (Underflow)!\n");
        return -999;
    }

    x = P->data[P->F];

    // If this was the last element, reset queue
    if (P->F == P->R) {
        P->F = -1;
        P->R = -1;
    } else {
        P->F = P->F + 1;
    }

    return x;
}

int dqdelete_rear(Q *P) {
    int x;

    if (P->R == -1) {
        printf("Queue is EMPTY (Underflow)!\n");
        return -999;
    }

    x = P->data[P->R];

    // If this was the last element, reset queue
    if (P->F == P->R) {
        P->F = -1;
        P->R = -1;
    } else {
        P->R = P->R - 1;
    }

    return x;
}

void Print(Q *P) {
    int i;
    if (P->F == -1) {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("Queue elements (front to rear): ");
    for (i = P->F; i <= P->R; i++) {
        printf("%d ", P->data[i]);
    }
    printf("\n");
}