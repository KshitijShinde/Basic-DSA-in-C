#include <stdio.h>

int fibonacci(int n);
void printFibonacciList(int n);

int main() {
    int n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a integer.\n");
    } else {
        printf("Fibonacci number at position %d is %d\n", n, fibonacci(n-1));
        printf("Fibonacci sequence position %d: ", n);
        printFibonacciList(n);
        printf("\n");
    }

    return 0;
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

void printFibonacciList(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
}
