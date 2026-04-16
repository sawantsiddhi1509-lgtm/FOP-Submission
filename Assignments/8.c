#include <stdio.h>

int main() {
    int m1, m2, m3, m4, m5;
    int total;
    float percentage;

    // Input
    printf("Enter marks of 5 subjects: ");
    scanf("%d %d %d %d %d", &m1, &m2, &m3, &m4, &m5);

    // Check pass/fail
    if(m1 < 40 || m2 < 40 || m3 < 40 || m4 < 40 || m5 < 40) {
        printf("\nResult: FAIL\n");
    } else {
        // Calculate total and percentage
        total = m1 + m2 + m3 + m4 + m5;
        percentage = total / 5.0;

        printf("\nTotal Marks = %d\n", total);
        printf("Percentage = %.2f%%\n", percentage);
        printf("Result: PASS\n");

        // Grade calculation
        if(percentage >= 75)
            printf("Grade: Distinction\n");
        else if(percentage >= 60)
            printf("Grade: First Division\n");
        else if(percentage >= 50)
            printf("Grade: Second Division\n");
        else
            printf("Grade: Third Division\n");
    }

    return 0;
}