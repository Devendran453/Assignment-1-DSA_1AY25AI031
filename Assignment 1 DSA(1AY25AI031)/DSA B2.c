#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int emp_id;

    enum { FULL_TIME, CONTRACT } type;

    union {
        float salary;
        struct {
            float hourly_rate;
            int hours_worked;
        } contract_info;
    } pay;

} Employee;

int main() {
    Employee *e;
    int n, i;
    float total_bill = 0, total_pay;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    e = (Employee *)malloc(n * sizeof(Employee));

    if (e == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter details of employee %d\n", i + 1);

        printf("Enter name: ");
        scanf("%19s", e[i].name);

        printf("Enter employee ID: ");
        scanf("%d", &e[i].emp_id);

        printf("Enter type (0 for Full-time, 1 for Contract): ");
        scanf("%d", (int *)&e[i].type);

        if (e[i].type == FULL_TIME) {
            printf("Enter monthly salary: ");
            scanf("%f", &e[i].pay.salary);
        } else if (e[i].type == CONTRACT) {
            printf("Enter hourly rate: ");
            scanf("%f", &e[i].pay.contract_info.hourly_rate);

            printf("Enter hours worked: ");
            scanf("%d", &e[i].pay.contract_info.hours_worked);
        } else {
            printf("Invalid employee type!\n");
            free(e);
            return 1;
        }
    }

    printf("\n------ EMPLOYEE PAYSLIPS ------\n");

    for (i = 0; i < n; i++) {
        printf("\nEmployee Name: %s\n", e[i].name);
        printf("Employee ID: %d\n", e[i].emp_id);

        if (e[i].type == FULL_TIME) {
            total_pay = e[i].pay.salary;
            printf("Type: Full-time\n");
        } else {
            total_pay = e[i].pay.contract_info.hourly_rate
                      * e[i].pay.contract_info.hours_worked;
            printf("Type: Contract\n");
        }

        printf("Total Pay: Rs. %.2f\n", total_pay);

        total_bill = total_bill + total_pay;
    }

    printf("\nTotal Salary Bill: Rs. %.2f\n", total_bill);

    free(e);

    return 0;
}

