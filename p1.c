#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int id;
    char name[50];
    float marks;
};

void addStudent();
void viewStudents();
void searchStudent();
void editStudent();
void deleteStudent();

int main()
{
    int choice;

    while(1)
    {
        system("cls");

        printf("\n===== STUDENT RECORD SYSTEM =====\n");

        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Edit Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                editStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice!");
        }

        printf("\nPress Enter to Continue...");
        getchar();
        getchar();
    }

    return 0;
}

void addStudent()
{
    FILE *fp;

    struct Student s;

    fp = fopen("students.dat", "ab");

    printf("Enter ID: ");
    scanf("%d", &s.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);

    fclose(fp);

    printf("Student Added Successfully!");
}

void viewStudents()
{
    FILE *fp;

    struct Student s;

    fp = fopen("students.dat", "rb");

    if(fp == NULL)
    {
        printf("No Records Found!");
        return;
    }

    printf("\n===== STUDENT LIST =====\n");

    while(fread(&s, sizeof(s), 1, fp))
    {
        printf("\nID    : %d", s.id);
        printf("\nName  : %s", s.name);
        printf("\nMarks : %.2f\n", s.marks);
    }

    fclose(fp);
}

void searchStudent()
{
    FILE *fp;

    struct Student s;

    int id, found = 0;

    fp = fopen("students.dat", "rb");

    if(fp == NULL)
    {
        printf("No Records Found!");
        return;
    }

    printf("Enter Student ID to Search: ");
    scanf("%d", &id);

    while(fread(&s, sizeof(s), 1, fp))
    {
        if(s.id == id)
        {
            printf("\n===== STUDENT FOUND =====\n");

            printf("ID    : %d\n", s.id);
            printf("Name  : %s\n", s.name);
            printf("Marks : %.2f\n", s.marks);

            found = 1;

            break;
        }
    }

    if(found == 0)
    {
        printf("Student Not Found!");
    }

    fclose(fp);
}

void editStudent()
{
    FILE *fp;

    struct Student s;

    int id, found = 0;

    fp = fopen("students.dat", "rb+");

    printf("Enter Student ID to Edit: ");
    scanf("%d", &id);

    while(fread(&s, sizeof(s), 1, fp))
    {
        if(s.id == id)
        {
            printf("Enter New Name: ");
            scanf(" %[^\n]", s.name);

            printf("Enter New Marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);

            fwrite(&s, sizeof(s), 1, fp);

            found = 1;

            printf("Record Updated Successfully!");

            break;
        }
    }

    if(found == 0)
    {
        printf("Record Not Found!");
    }

    fclose(fp);
}

void deleteStudent()
{
    FILE *fp, *temp;

    struct Student s;

    int id, found = 0;

    fp = fopen("students.dat", "rb");

    temp = fopen("temp.dat", "wb");

    printf("Enter Student ID to Delete: ");
    scanf("%d", &id);

    while(fread(&s, sizeof(s), 1, fp))
    {
        if(s.id == id)
        {
            found = 1;
            continue;
        }

        fwrite(&s, sizeof(s), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");

    rename("temp.dat", "students.dat");

    if(found == 1)
    {
        printf("Record Deleted Successfully!");
    }
    else
    {
        printf("Record Not Found!");
    }
}