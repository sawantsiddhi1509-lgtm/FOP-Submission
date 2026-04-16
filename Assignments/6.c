#include <stdio.h>

// Recursive function
int factorial_recursive(int n) {
    if(n == 0 || n == 1)
        return 1;
    else
        return n * factorial_recursive(n - 1);
}

int main() {
    int n, i;
    int fact_iter = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Check invalid input
    if(n < 0) {
        printf("Factorial not defined for negative numbers\n");
        return 0;
    }

    // Iterative (without recursion)
    for(i = 1; i <= n; i++) {
        fact_iter *= i;
    }

    // Recursive
    int fact_rec = factorial_recursive(n);

    // Output
    printf("\nFactorial (Iterative) = %d\n", fact_iter);
    printf("Factorial (Recursive) = %d\n", fact_rec);

    return 0;
}