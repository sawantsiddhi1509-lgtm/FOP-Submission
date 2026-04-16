#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100];
    int choice;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    printf("1.Length\n2.Copy\n3.Concatenate\n4.Compare\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Length = %lu\n", strlen(str1));
            break;

        case 2:
            strcpy(str2, str1);
            printf("Copied string: %s\n", str2);
            break;

        case 3:
            strcat(str1, str2);
            printf("Concatenated string: %s\n", str1);
            break;

        case 4:
            if (strcmp(str1, str2) == 0)
                printf("Strings are equal\n");
            else
                printf("Strings are not equal\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}