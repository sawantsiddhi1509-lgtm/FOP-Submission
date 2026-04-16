#include <stdio.h>
#include <string.h>

struct employee
{
    char name[50];
    char designation[50];
    char gender[10];
    float salary;
};

int main()
{
    struct employee e[100];
    int n, i, male = 0, female = 0;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter details of employee %d:\n", i + 1);
        scanf("%s %s %s %f", e[i].name, e[i].designation, e[i].gender, &e[i].salary);

        if (strcmp(e[i].gender, "Male") == 0)
            male++;
        else
            female++;
    }

    printf("Total employees = %d\n", n);
    printf("Male = %d\n", male);
    printf("Female = %d\n", female);

    printf("Salary > 10000:\n");
    for (i = 0; i < n; i++)
    {
        if (e[i].salary > 10000)
            printf("%s\n", e[i].name);
    }

    printf("Asst Manager:\n");
    for (i = 0; i < n; i++)
    {
        if (strcmp(e[i].designation, "AsstManager") == 0)
            printf("%s\n", e[i].name);
    }

    return 0;
}