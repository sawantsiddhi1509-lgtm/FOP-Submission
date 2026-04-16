#include <stdio.h>

int main() {
    int choice;
    float num1, num2, result;

    // Display Menu
    printf("\nMENU:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    // Input choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Input numbers
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    // Switch-case for operations
    switch(choice) {
        case 1:
            result = num1 + num2;
            printf("Addition = %.2f\n", result);
            break;

        case 2:
            result = num1 - num2;
            printf("Subtraction = %.2f\n", result);
            break;

        case 3:
            result = num1 * num2;
            printf("Multiplication = %.2f\n", result);
            break;

        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                printf("Division = %.2f\n", result);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}