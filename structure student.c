#include <stdio.h>

struct Student
{
    char name[50];
    int age;
    float marks;
};

int main()
{
    struct Student s;

    printf("Enter Name: ");
    scanf("%s", s.name);

    printf("Enter Age: ");
    scanf("%d", &s.age);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    printf("\nStudent Details\n");
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Marks: %.2f\n", s.marks);

    return 0;
}