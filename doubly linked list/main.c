#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the doubly linked list
typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} node;

// Function to create a new node
node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
node* insertAtBeginning(node* head, int data) {
    node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;  // If the list is empty, return the new node as the head
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;  // Return the new head of the list
}

// Function to insert a node at the end
node* insertAtEnd(node* head, int data) {
    node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;  // If the list is empty, return the new node as the head
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;  // Return the unchanged head of the list
}

// Function to insert a node at a specified position
node* insertAtMiddle(node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return head;
    }
    if (position == 1) {
        return insertAtBeginning(head, data);
    }

    node* newNode = createNode(data);
    node* temp = head;

    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Position out of bounds! Inserting at the end.\n");
            return insertAtEnd(head, data);
        }
        temp = temp->next;
    }

    if (temp->next == NULL) {  // If inserting at the end
        return insertAtEnd(head, data);
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

// Function to delete the first node
node* deleteFirstNode(node* head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }
    node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

// Function to delete a node at the end
node* deleteAtEnd(node* head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    return head;
}

// Function to delete a node at a specified position
node* deleteAtMiddle(node* head, int position) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }

    if (position < 1) {
        printf("Invalid position!\n");
        return head;
    }

    if (position == 1) {
        return deleteFirstNode(head);
    }

    node* temp = head;
    for (int i = 1; i < position; i++) {
        if (temp == NULL) {
            printf("Position out of bounds, nothing to delete.\n");
            return head;
        }
        temp = temp->next;
    }

    if (temp->next == NULL) {
        return deleteAtEnd(head);  // If the node is the last one
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);

    return head;
}

// Function to display the doubly linked list
void displayList(node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to count the number of nodes
int countNodes(node* head) {
    int count = 0;
    node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to search for a node by value
int searchNode(node* head, int key) {
    int position = 1;
    node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            return position;  // Node found, return its position
        }
        temp = temp->next;
        position++;
    }
    return -1;  // Node not found
}

// Function to reverse the doubly linked list
node* reverseList(node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    node* temp = NULL;
    node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;  // Set the new head of the reversed list
    }

    return head;
}

// Main function to demonstrate the menu-driven program
int main() {
    node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert node at beginning\n");
        printf("2. Insert node at middle\n");
        printf("3. Insert node at end\n");
        printf("4. Delete first node\n");
        printf("5. Delete node at middle\n");
        printf("6. Delete last node\n");
        printf("7. Display list\n");
        printf("8. Count number of nodes\n");
        printf("9. Search a node\n");
        printf("10. Reverse the list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;

            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                head = insertAtMiddle(head, data, position);
                break;

            case 3:
                printf("Enter the value to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;

            case 4:
                head = deleteFirstNode(head);
                break;

            case 5:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                head = deleteAtMiddle(head, position);
                break;

            case 6:
                head = deleteAtEnd(head);
                break;

            case 7:
                displayList(head);
                break;

            case 8:
                printf("Number of nodes: %d\n", countNodes(head));
                break;

            case 9:
                printf("Enter the value to search: ");
                scanf("%d", &data);
                position = searchNode(head, data);
                if (position != -1) {
                    printf("Node found at position %d.\n", position);
                } else {
                    printf("Node not found.\n");
                }
                break;

            case 10:
                head = reverseList(head);
                printf("List reversed.\n");
                break;

            case 11:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
