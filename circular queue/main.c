#include <stdio.h>

int queue[100];
int SIZE;
int f = -1;  
int r = -1;  

void enqueue(int value) {
    if ((f == 0 && r == SIZE - 1)) {
        printf("Queue is full \n");
    } else if (f == -1) {  
        f = r = 0;
        queue[r] = value;
    } else if (r == SIZE - 1 && f != 0) {
        r = 0;
        queue[r] = value;
    } else {  
        r++;
        queue[r] = value;
    }
}

void dequeue() {
    if (f == -1) {
        printf("Queue underflow\n");
    } else if (f == r) {  
        printf("Dequeued element: %d\n", queue[f]);
        f = r = -1;
    } else if (f == SIZE - 1) {  
        printf("Dequeued element: %d\n", queue[f]);
        f = 0;
    } else {  
        printf("Dequeued element: %d\n", queue[f]);
        f++;
    }
}

void display() {
    if (f == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    if (r >= f) {
        for (int i = f; i <= r; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = 0; i <= r; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = f; i < SIZE; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    printf("enter size of queue : ");
    scanf("%d",&SIZE);
    int choice, value;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
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
