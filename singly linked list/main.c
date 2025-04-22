#include <stdio.h>
#include <stdlib.h>

// Define the node structure and create a type alias for it
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;  // New node points to the old head
    return newNode;  // Return the new head of the list
}

// Function to insert a node at the end
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;  // If the list is empty, return the new node as the head
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;  // Traverse to the end of the list
    }
    temp->next = newNode;  // Link the new node at the end
    return head;  // Return the unchanged head pointer
}

// Function to insert a node at a specified position
Node* insertAtPosition(Node* head, int data, int position) {
    if (position < 0) {
        printf("Invalid position! Position must be non-negative.\n");
        return head;  // Return unchanged head if position is invalid
    }

    if (position == 0) {
        return insertAtBeginning(head, data);  // Insert at the beginning
    }

    Node* newNode = createNode(data);
    Node* temp = head;

    // Traverse to the position just before where we want to insert
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Position out of bounds! Inserting at the end instead.\n");
            return insertAtEnd(head, data);  // If the position is out of bounds, insert at the end
        }
        temp = temp->next;
    }

    // Insert the new node at the specified position
    if (temp != NULL) {
        newNode->next = temp->next;  // Link the new node to the next node
        temp->next = newNode;  // Link the previous node to the new node
    }

    return head;  // Return the unchanged head pointer
}

// Function to delete a node at the beginning
Node* deleteAtBeginning(Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }
    
    Node* temp = head;
    head = head->next;  // Update head to the next node
    free(temp);  // Free the old head node
    return head;  // Return new head
}

// Function to delete a node at the end
Node* deleteAtEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    // If the list has only one node
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;  // Traverse to the end
    }

    prev->next = NULL;  // Disconnect the last node
    free(temp);  // Free the last node
    return head;  // Return the unchanged head
}

// Function to delete a node in between
Node* deleteInBetween(Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    if (position < 0) {
        printf("Invalid position! Position must be non-negative.\n");
        return head;  // Return unchanged head if position is invalid
    }

    // If deleting the first node
    if (position == 0) {
        return deleteAtBeginning(head);
    }

    Node* current = head;
    Node* previous = NULL;

    for (int i = 0; i < position; i++) {
        if (current == NULL) {
            printf("Position out of bounds! Nothing to delete.\n");
            return head;  // Return unchanged head if position is out of bounds
        }
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of bounds! Nothing to delete.\n");
        return head;  // Return unchanged head
    }

    previous->next = current->next;  // Unlink the node
    free(current);  // Free the memory of the node
    return head;  // Return the unchanged head
}

// Function to count the number of nodes
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    return count;
}

// Function to search for a node by value
int searchNode(Node* head, int key) {
    Node* temp = head;
    int position = 0;

    while (temp != NULL) {
        if (temp->data == key) {
            return position;  // Return the position if the value is found
        }
        temp = temp->next;
        position++;
    }

    return -1;  // Return -1 if the value is not found
}

// Main function to demonstrate the linked list operations
int main() {
    Node* head = NULL;  // Head of the linked list

    int choice, data, position;
    while (1) {
        // Display menu for user
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete In Between\n");
        printf("7. Count Nodes\n");
        printf("8. Search a Node\n");
        printf("9. Print List\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                printf("Node inserted at the beginning.\n");
                break;

            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                printf("Node inserted at the end.\n");
                break;

            case 3:
                printf("Enter the value to insert at position: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                printf("Node inserted at position %d.\n", position);
                break;

            case 4:
                head = deleteAtBeginning(head);
                printf("Node deleted at the beginning.\n");
                break;

            case 5:
                head = deleteAtEnd(head);
                printf("Node deleted at the end.\n");
                break;

            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                head = deleteInBetween(head, position);
                printf("Node deleted at position %d.\n", position);
                break;

            case 7:
                printf("The number of nodes in the list: %d\n", countNodes(head));
                break;

            case 8:
                printf("Enter the value to search: ");
                scanf("%d", &data);
                position = searchNode(head, data);
                if (position != -1) {
                    printf("Node found at position %d.\n", position);
                } else {
                    printf("Node not found in the list.\n");
                }
                break;

            case 9:
                printf("Current Linked List: ");
                printList(head);
                break;

            case 10:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}
