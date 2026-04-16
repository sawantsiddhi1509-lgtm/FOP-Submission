#include <stdio.h>
#include <math.h>

int main() {
    int binary, digit, i = 0;
    int decimal = 0;

    printf("Enter a binary number: ");
    scanf("%d", &binary);

    while(binary != 0) {
        digit = binary % 10;                 // get last digit
        decimal += digit * pow(2, i);        // add 2^i
        binary = binary / 10;                // remove last digit
        i++;
    }

    printf("Decimal equivalent = %d\n", decimal);

    return 0;
}