#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    int id;
    char name[50];
    char author[50];
};

void addBook();
void viewBooks();
void searchBook();
void editBook();
void deleteBook();

int main()
{
    int choice;

    while(1)
    {
        system("cls");

        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");

        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Edit Book\n");
        printf("5. Delete Book\n");
        printf("6. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                viewBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                editBook();
                break;

            case 5:
                deleteBook();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice!");
        }

        printf("\n\nPress Enter to Continue...");
        getchar();
        getchar();
    }

    return 0;
}

void addBook()
{
    FILE *fp;

    struct Book b;

    fp = fopen("library.dat", "ab");

    if(fp == NULL)
    {
        printf("File Error!");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &b.id);

    printf("Enter Book Name: ");
    scanf(" %[^\n]", b.name);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", b.author);

    fwrite(&b, sizeof(b), 1, fp);

    fclose(fp);

    printf("Book Added Successfully!");
}

void viewBooks()
{
    FILE *fp;

    struct Book b;

    fp = fopen("library.dat", "rb");

    if(fp == NULL)
    {
        printf("No Records Found!");
        return;
    }

    printf("\n===== BOOK LIST =====\n");

    while(fread(&b, sizeof(b), 1, fp))
    {
        printf("\nBook ID     : %d", b.id);
        printf("\nBook Name   : %s", b.name);
        printf("\nAuthor Name : %s\n", b.author);
    }

    fclose(fp);
}

void searchBook()
{
    FILE *fp;

    struct Book b;

    int id, found = 0;

    fp = fopen("library.dat", "rb");

    if(fp == NULL)
    {
        printf("No Records Found!");
        return;
    }

    printf("Enter Book ID to Search: ");
    scanf("%d", &id);

    while(fread(&b, sizeof(b), 1, fp))
    {
        if(b.id == id)
        {
            printf("\n===== BOOK FOUND =====\n");

            printf("Book ID     : %d\n", b.id);
            printf("Book Name   : %s\n", b.name);
            printf("Author Name : %s\n", b.author);

            found = 1;

            break;
        }
    }

    if(found == 0)
    {
        printf("Book Not Found!");
    }

    fclose(fp);
}

void editBook()
{
    FILE *fp;

    struct Book b;

    int id, found = 0;

    fp = fopen("library.dat", "rb+");

    if(fp == NULL)
    {
        printf("No Records Found!");
        return;
    }

    printf("Enter Book ID to Edit: ");
    scanf("%d", &id);

    while(fread(&b, sizeof(b), 1, fp))
    {
        if(b.id == id)
        {
            printf("Enter New Book Name: ");
            scanf(" %[^\n]", b.name);

            printf("Enter New Author Name: ");
            scanf(" %[^\n]", b.author);

            fseek(fp, -sizeof(b), SEEK_CUR);

            fwrite(&b, sizeof(b), 1, fp);

            found = 1;

            printf("Book Updated Successfully!");

            break;
        }
    }

    if(found == 0)
    {
        printf("Book Not Found!");
    }

    fclose(fp);
}

void deleteBook()
{
    FILE *fp, *temp;

    struct Book b;

    int id, found = 0;

    fp = fopen("library.dat", "rb");

    temp = fopen("temp.dat", "wb");

    if(fp == NULL)
    {
        printf("No Records Found!");
        return;
    }

    printf("Enter Book ID to Delete: ");
    scanf("%d", &id);

    while(fread(&b, sizeof(b), 1, fp))
    {
        if(b.id == id)
        {
            found = 1;
            continue;
        }

        fwrite(&b, sizeof(b), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("library.dat");

    rename("temp.dat", "library.dat");

    if(found == 1)
    {
        printf("Book Deleted Successfully!");
    }
    else
    {
        printf("Book Not Found!");
    }
}