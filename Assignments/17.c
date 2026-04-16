#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    float x, sum = 0;

    printf("Enter value of x (in radians): ");
    scanf("%f", &x);

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        int j;
        float fact = 1;

        for (j = 1; j <= (2 * i - 1); j++)
        {
            fact = fact * j;
        }

        if (i % 2 != 0)
            sum = sum + pow(x, 2 * i - 1) / fact;
        else
            sum = sum - pow(x, 2 * i - 1) / fact;
    }

    printf("Sum of sine series = %f\n", sum);

    return 0;
}