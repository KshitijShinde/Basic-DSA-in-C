#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* create(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    if (!newnode) {
        printf("Memory error\n");
        return NULL;
    }
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node* insert(node* root, int data) {
    node* newnode = create(data);
    if (root == NULL) {
        return newnode;  
    }

    node* current = root;
    node* parent = NULL;

    while (current != NULL) {
        parent = current;

        if (data < current->data) {
            current = current->left;  
        } else {
            current = current->right; 
        }
    }

    if (data < parent->data) {
        parent->left = newnode;
    } else {
        parent->right = newnode;
    }

    return root;
}

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);  
        printf("%d ", root->data); 
        inorder(root->right);  
    }
}

void preorder(node* root) {
    if (root != NULL) {
        printf("%d ", root->data); 
        preorder(root->left);      
        preorder(root->right);     
    }
}

void postorder(node* root) {
    if (root != NULL) {
        postorder(root->left);    
        postorder(root->right);   
        printf("%d ", root->data); 
    }
}

int main() {
    node* root = NULL;
    int data, choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter node value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);  // Insert node into the tree
                printf("Node inserted.\n");
                break;

            case 2:
                printf("Inorder traversal: ");
                inorder(root);  // Inorder traversal (Left → Root → Right)
                printf("\n");
                break;

            case 3:
                printf("Preorder traversal: ");
                preorder(root); // Preorder traversal (Root → Left → Right)
                printf("\n");
                break;

            case 4:
                printf("Postorder traversal: ");
                postorder(root); // Postorder traversal (Left → Right → Root)
                printf("\n");
                break;

            case 5:
                printf("Exiting the program.\n");
                return 0;  // Exit the program

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
