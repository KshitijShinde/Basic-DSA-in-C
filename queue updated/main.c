#include <stdio.h>

int queue[100];
int max;
int front = -1;
int end = -1;

void enq() {
    int x;
    if (end == max - 1) {
        printf("Queue is full (overflow)...\n");
    } else {
        printf("Enter element in queue: ");
        scanf("%d", &x);
        if (front == -1) {
            front = 0;
        }
        end++;
        queue[end] = x;
        printf("Element %d added to the queue.\n", x);
    }
}

void deq() {
    if (front == -1) {
        printf("Queue is empty (underflow)...\n");
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        if (front == end) {
            front = -1;
            end = -1;
        } else {
            front++;
        }
    }
}

void dis() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= end; i++) {
            printf("|%d", queue[i]);
        }
        printf("|\n");
    }
}

int main() {
    printf("Enter the size of the queue: ");
    scanf("%d", &max);

    int choice;
    do {
        printf("\nEnter choice:\n1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                enq();
                break;
            case 2:
                deq();
                break;
            case 3:
                printf("Displaying queue:\n");
                dis();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    
    return 0;
}
