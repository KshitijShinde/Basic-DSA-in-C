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

// Function to concatenate two lists
Node* concatenateLists(Node* head1, Node* head2) {
    if (head1 == NULL) {
        return head2;  // If the first list is empty, return the second list
    }
    if (head2 == NULL) {
        return head1;  // If the second list is empty, return the first list
    }

    Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;  // Traverse to the end of the first list
    }
    temp->next = head2;  // Link the end of the first list to the beginning of the second list
    return head1;
}

// Main function to demonstrate the linked list concatenation
int main() {
    Node* list1 = NULL;  // First linked list
    Node* list2 = NULL;  // Second linked list

    // Insert values into the first list
    list1 = insertAtEnd(list1, 1);
    list1 = insertAtEnd(list1, 2);
    list1 = insertAtEnd(list1, 3);
    
    // Insert values into the second list
    list2 = insertAtEnd(list2, 4);
    list2 = insertAtEnd(list2, 5);
    list2 = insertAtEnd(list2, 6);

    // Print both lists
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    // Concatenate the lists
    list1 = concatenateLists(list1, list2);

    // Print the concatenated list
    printf("Concatenated List: ");
    printList(list1);

    return 0;
}
