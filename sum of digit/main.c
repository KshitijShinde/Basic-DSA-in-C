#include <stdio.h>

// Function to calculate the sum of digits using recursion
int sumOfDigits(int n) {
    if (n == 0)  // Base case: when n is 0, return 0
        return 0;
    else
        return (n % 10) + sumOfDigits(n / 10);  // Recursive case: add last digit and recurse for the rest
}

int main() {
    int num;
    
    // Input the number
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // Call the recursive function and print the result
    int sum = sumOfDigits(num);
    printf("Sum of digits of %d is: %d\n", num, sum);
    
    return 0;
}
