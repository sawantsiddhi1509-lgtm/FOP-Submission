#include <stdio.h>

int main()
{
    FILE *f1, *f2;
    char ch;

    f1 = fopen("source.txt", "r");
    f2 = fopen("destination.txt", "w");

    if (f1 == NULL || f2 == NULL)
    {
        printf("Error opening file\n");
        return 0;
    }

    while ((ch = fgetc(f1)) != EOF)
    {
        fputc(ch, f2);
    }

    printf("File copied successfully\n");

    fclose(f1);
    fclose(f2);

    return 0;
}