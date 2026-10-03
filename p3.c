#include <stdio.h>

int main()
{
    char gender, qualification;
    int y;

    printf("Enter your Gender (M/F), Years of service, Qualification (G/P): ");
    scanf(" %c %d %c", &gender, &y, &qualification);

    if (gender == 'M')
    {
        if (y < 10)
        {
            if (qualification == 'G')
            {
                printf("Salary is 7000");
            }
            else if (qualification == 'P')
            {
                printf("Salary is 10000");
            }
            else
            {
                printf("Invalid qualification");
            }
        }
        else
        {
            if (qualification == 'G')
            {
                printf("Salary is 10000");
            }
            else if (qualification == 'P')
            {
                printf("Salary is 15000");
            }
            else
            {
                printf("Invalid qualification");
            }
        }
    }
    else if (gender == 'F')
    {
        if (y >= 10)
        {
            if (qualification == 'G')
            {
                printf("Salary is 9000");
            }
            else if (qualification == 'P')
            {
                printf("Salary is 12000");
            }
            else
            {
                printf("Invalid qualification");
            }
        }
        else
        {
            if (qualification == 'G')
            {
                printf("Salary is 6000");
            }
            else if (qualification == 'P')
            {
                printf("Salary is 10000");
            }
            else
            {
                printf("Invalid qualification");
            }
        }
    }
    else
    {
        printf("Invalid gender");
    }

    return 0;
}