#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll_no;
    char name[20];
    float marks;
};

int main()
{
    struct Student *ptr, *temp;
    int n, i;
    float sum = 0, average;
    int top = 0;
    char choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    ptr = (struct Student *)malloc(n * sizeof(struct Student));

    if (ptr == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter roll, name, marks: ");
        scanf("%d %19s %f",
              &(ptr + i)->roll_no,
              (ptr + i)->name,
              &(ptr + i)->marks);
    }

    for (i = 0; i < n; i++)
    {
        sum = sum + (ptr + i)->marks;

        if ((ptr + i)->marks > (ptr + top)->marks)
        {
            top = i;
        }
    }

    average = sum / n;

    printf("\nAverage marks: %.2f\n", average);
    printf("Topper: %s (Roll %d, Marks %.2f)\n",
           (ptr + top)->name,
           (ptr + top)->roll_no,
           (ptr + top)->marks);

    printf("\nAdd 2 more students? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        temp = (struct Student *)realloc(
            ptr, (n + 2) * sizeof(struct Student));

        if (temp == NULL)
        {
            printf("Memory reallocation failed!\n");
            free(ptr);
            return 1;
        }

        ptr = temp;

        for (i = n; i < n + 2; i++)
        {
            printf("Enter roll, name, marks: ");
            scanf("%d %19s %f",
                  &(ptr + i)->roll_no,
                  (ptr + i)->name,
                  &(ptr + i)->marks);
        }

        n = n + 2;
        sum = 0;

        for (i = 0; i < n; i++)
        {
            sum = sum + (ptr + i)->marks;
        }

        average = sum / n;

        printf("Updated average marks: %.2f\n", average);
    }

    free(ptr);

    return 0;
}

