#include <stdio.h>

int main() {
    float basic, hra, ta, gross, tax, net;

    // Input
    printf("Enter Basic Salary: ");
    scanf("%f", &basic);

    // Calculations
    hra = 0.10 * basic;       // 10% HRA
    ta  = 0.05 * basic;       // 5% TA

    gross = basic + hra + ta; // Gross Salary

    tax = 0.02 * gross;       // 2% Professional Tax

    net = gross - tax;        // Net Salary

    // Output
    printf("\nHRA = %.2f", hra);
    printf("\nTA = %.2f", ta);
    printf("\nGross Salary = %.2f", gross);
    printf("\nProfessional Tax = %.2f", tax);
    printf("\nNet Salary = %.2f\n", net);

    return 0;
}