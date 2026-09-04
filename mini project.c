#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

void addEmployee()
{
    struct Employee e;
    FILE *fp;

    fp = fopen("employee.dat", "ab");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &e.id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", e.name);

    printf("Enter Salary: ");
    scanf("%f", &e.salary);

    fwrite(&e, sizeof(e), 1, fp);

    fclose(fp);

    printf("Employee added successfully!\n");
}

void displayEmployees()
{
    struct Employee e;
    FILE *fp;

    fp = fopen("employee.dat", "rb");

    if (fp == NULL)
    {
        printf("No employee records found.\n");
        return;
    }

    printf("\n--- Employee Details ---\n");

    while (fread(&e, sizeof(e), 1, fp))
    {
        printf("ID     : %d\n", e.id);
        printf("Name   : %s\n", e.name);
        printf("Salary : %.2f\n", e.salary);
        printf("------------------------\n");
    }

    fclose(fp);
}

int main()
{
    int choice;

    do
    {
        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                printf("Program exited.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}