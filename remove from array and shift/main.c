#include <stdio.h>

int main() {
    int n, position, i;
    
    // Input the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Input elements of the array
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input the position of the element to delete
    printf("Enter the position of the element to delete (0-based index): ");
    scanf("%d", &position);
    
    // Check if the position is valid
    if(position < 0 || position >= n) {
        printf("Invalid position!\n");
        return 1;
    }
    
    // Display the original array
    printf("Original array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Delete the element at the specified position
    for(i = position; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    // Reduce the size of the array
    n--;
    
    // Display the modified array
    printf("Array after deletion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
