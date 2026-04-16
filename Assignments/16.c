#include <stdio.h>

int main()
{
    int n, i, arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Even numbers are: ");
    for (i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
            printf("%d ", arr[i]);
    }

    printf("\nOdd numbers are: ");
    for (i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
            printf("%d ", arr[i]);
    }

    return 0;
}