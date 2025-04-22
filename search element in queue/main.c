#include <stdio.h>

void search(int queue[], int front, int end) {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    int element, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &element);

    for (int i = front; i <= end; i++) {
        if (queue[i] == element) {
            printf("Element %d found at position %d in the queue.\n", element, i - front + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the queue.\n", element);
    }
}

int main() {
    int queue[] = {10, 20, 30, 40, 50}; // Example queue
    int front = 0, end = 4;  // Front and end indices

    search(queue, front, end);

    return 0;
}
