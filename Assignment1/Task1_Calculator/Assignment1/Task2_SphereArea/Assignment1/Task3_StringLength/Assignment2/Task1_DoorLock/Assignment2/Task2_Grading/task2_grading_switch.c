#include <stdio.h>

int main(void)
{
    int n;

    printf("How many students? ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid number of students.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++)
    {
        int regNo;
        char name[50];
        int marks;
        char grade;
        const char *status;

        printf("\n--- Student %d of %d ---\n", i, n);

        printf("Registration number: ");
        scanf("%d", &regNo);

        printf("Name: ");
        scanf(" %49[^\n]", name);

        do
        {
            printf("Marks (0-100): ");
            scanf("%d", &marks);
            if (marks < 0 || marks > 100)
            {
                printf("Marks must be between 0 and 100.\n");
            }
        } while (marks < 0 || marks > 100);

        /* marks / 10 gives the tens digit: 100 -> 10, 85 -> 8, 42 -> 4 ... */
        switch (marks / 10)
        {
        case 10:
        case 9:
        case 8:
        case 7:
            grade = 'A';
            status = "Passed";
            break;
        case 6:
            grade = 'B';
            status = "Passed";
            break;
        case 5:
            grade = 'C';
            status = "Passed";
            break;
        case 4:
            grade = 'D';
            status = "Passed";
            break;
        default:
            grade = 'F';
            status = "Failed";
        }

        printf("\n---------------------------------\n");
        printf("       STUDENT INFORMATION\n");
        printf("---------------------------------\n");
        printf("Registration No: %d\n", regNo);
        printf("Name: %s\n", name);
        printf("Marks: %d\n", marks);
        printf("Grade: %c\n", grade);
        printf("Status: %s\n", status);
        printf("---------------------------------\n");
    }

    return 0;
}
