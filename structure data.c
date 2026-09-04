#include <stdio.h>

struct Student
{
    char name[50];
    int age;
    float marks;
};

int main()
{
    struct Student s, s1;
    FILE *fp;

    printf("Enter Name: ");
    scanf("%s", s.name);

    printf("Enter Age: ");
    scanf("%d", &s.age);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fp = fopen("student.dat", "wb");

    if (fp == NULL)
    {
        printf("File cannot be opened.");
        return 1;
    }

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    fp = fopen("student.dat", "rb");

    fread(&s1, sizeof(s1), 1, fp);
    fclose(fp);

    printf("\nData Read From File\n");
    printf("Name: %s\n", s1.name);
    printf("Age: %d\n", s1.age);
    printf("Marks: %.2f\n", s1.marks);

    return 0;
}