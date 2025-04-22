#include <stdio.h>

int stack[100];  // Max size is fixed to 100, but actual size will be set by the user
int top = -1;
int size;

void push();
void pop();
int is_empty();
int is_full();
void display();

int main()
{
    int choice;

    // Taking the size of the stack from the user
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    if (size > 100 || size <= 0) {
        printf("Invalid stack size. Please enter a size between 1 and 100.\n");
        return -1;
    }

    do
    {
        printf("\nEnter choice:\n1 : Push\n2 : Pop\n3 : Display\n4 : Check if Empty\n5 : Check if Full\n6 : Exit\n");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                if (is_empty())
                    printf("Stack is empty.\n");
                else
                    printf("Stack is not empty.\n");
                break;
            case 5:
                if (is_full())
                    printf("Stack is full.\n");
                else
                    printf("Stack is not full.\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    while (choice != 6);

    return 0;
}

void push()
{
    int n;
    if (is_full())
    {
        printf("STACK OVERFLOW\n");
    }
    else 
    {
        printf("Enter the element: ");
        scanf("%d", &n);
        top++;
        stack[top] = n;
        printf("%d pushed onto stack.\n", n);
    }
}

void pop()
{
    int item;
    if (is_empty())
    {
        printf("STACK UNDERFLOW\n");
    }
    else 
    {
        item = stack[top];
        top--;
        printf("%d popped from stack.\n", item);
    }
}

int is_empty()
{
    return top == -1;
}

int is_full()
{
    return top == size - 1;
}

void display()
{
    if (is_empty())
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("|%d|\n", stack[i]);
        }
        printf("\n");
    }
}
