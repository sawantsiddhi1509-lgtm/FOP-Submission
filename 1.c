#include <stdio.h>

int main() {
    int year;

    // Input
    printf("Enter a year: ");
    scanf("%d", &year);

    // Check leap year
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        printf("%d is a Leap Year\n", year);
    } else {
        printf("%d is Not a Leap Year\n", year);
    }

    return 0;
}