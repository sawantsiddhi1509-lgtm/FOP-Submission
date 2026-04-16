#include <stdio.h>

// Function (Call by Value)
void swapValue(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;

    printf("\nAfter swapping without pointers:\n");
    printf("a = %d b = %d\n", a, b);
}

// Function (Call by Reference using pointers)
void swapPointer(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Call by Value
    swapValue(a, b);

    // Call by Reference
    swapPointer(&a, &b);

    printf("\nAfter swapping with pointers:\n");
    printf("a = %d b = %d\n", a, b);

    return 0;
}