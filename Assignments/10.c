#include <stdio.h>

int main() {
    int choice, i, n;
    float a, b, result = 1;

    // Menu
    printf("\nCalculator Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power (x^y)\n");
    printf("6. Factorial (x!)\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter two numbers: ");
            scanf("%f %f", &a, &b);
            printf("Result = %.2f\n", a + b);
            break;

        case 2:
            printf("Enter two numbers: ");
            scanf("%f %f", &a, &b);
            printf("Result = %.2f\n", a - b);
            break;

        case 3:
            printf("Enter two numbers: ");
            scanf("%f %f", &a, &b);
            printf("Result = %.2f\n", a * b);
            break;

        case 4:
            printf("Enter two numbers: ");
            scanf("%f %f", &a, &b);
            if(b != 0)
                printf("Result = %.2f\n", a / b);
            else
                printf("Error: Division by zero\n");
            break;

        case 5:
            printf("Enter base and exponent: ");
            scanf("%f %f", &a, &b);
            result = 1;
            for(i = 1; i <= (int)b; i++)
                result *= a;
            printf("Result = %.2f\n", result);
            break;

        case 6:
            printf("Enter a number: ");
            scanf("%d", &n);
            result = 1;
            for(i = 1; i <= n; i++)
                result *= i;
            printf("Result = %.0f\n", result);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}