#include <stdio.h>

int main() {
    int n, digit;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Digits in reverse order: ");

    while(n != 0) {
        digit = n % 10;     // get last digit
        printf("%d ", digit);
        n = n / 10;         // remove last digit
    }

    printf("\n");

    return 0;
}