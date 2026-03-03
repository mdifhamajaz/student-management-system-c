#include <stdio.h>
#include <string.h>

void printMenu();
int scanMenu();
void addStudent(char students[1000][20]);
void displayStudents(char students[1000][20]);
void searchStudent(char students[1000][20]);
void deleteStudent(char students[1000][20]);
void updateStudent(char students[1000][20]);
int count_of_std = 0;

int main()
{
    char students[1000][20];

    int choice;

    do
    {
        printMenu();
        choice = scanMenu();

        if (choice == 1)
        {
            if (count_of_std < 1000)
            {
                addStudent(students);
            }
            else
            {
                printf("Database is full, Can't add more students!\n");
            }
        }
        if (choice == 2)
        {
            displayStudents(students);
        }

        if (choice == 3)
        {
            searchStudent(students);
        }
        if (choice == 4)
        {
            deleteStudent(students);
        }
        if (choice == 5)
        {
            updateStudent(students);
        }

    } while (choice != 0);

    return 0;
}

void printMenu()
{

    printf("1: Add students\n");
    printf("2: Display students\n");
    printf("3: Search student\n");
    printf("4: Delete student\n");
    printf("5: Update student\n");
    printf("0: Exit\n");
}

int scanMenu()
{
    int choice;

    printf("Enter your choice serial no: ");
    scanf("%d", &choice);

    return choice;
}

void addStudent(char students[1000][20])
{

    char name[20];

    do
    {
        printf("Enter the name of student to add(Enter done if done adding): ");
        scanf(" %19s", name);

        if (strcmp(name, "done") == 0)
        {
            break;
        }
        strcpy(students[count_of_std], name);
        count_of_std++;

        printf("Added %s\n", name);
    } while (strcmp(name, "done") != 0);
}

void displayStudents(char students[1000][20])
{
    char name[20];

    do
    {
        if (count_of_std != 0)
        {
            for (int i = 0; i < count_of_std; i++)
            {
                printf("%d: %s\n", i + 1, students[i]);
            }
        }
        else
        {
            printf("No students added yet!\n");
        }
        printf("\nEnter done to go to main menu: ");
        scanf(" %19s", name);
    } while (strcmp(name, "done") != 0);
}

void searchStudent(char students[1000][20])
{
    char name[20];
    if (count_of_std == 0)
    {
        printf("No students available!\n\n");
        return;
    }

    do
    {
        int isFound = 0;
        printf("Enter the name of student you want to search(Enter done if done sarching): ");
        scanf(" %19s", name);

        if (strcmp(name, "done") == 0)
        {
            break;
        }

        for (int i = 0; i < count_of_std; i++)
        {
            if (strcmp(name, students[i]) == 0)
            {
                isFound = 1;
                break;
            }
        }
        if (isFound)
        {
            printf("Student is present in the database\n");
        }
        else
        {
            printf("Student is not present in the database\n");
        }
    } while (strcmp(name, "done") != 0);
}
void deleteStudent(char students[1000][20])
{
    char name[20];
    char confirmation;
    int index = 0;
    if (count_of_std == 0)
    {
        printf("No students available!\n\n");
        return;
    }

    do
    {
        int isFound = 0;
        printf("Enter the name of student to delete(Enter done if done deleting): ");
        scanf(" %19s", name);

        if (strcmp(name, "done") == 0)
        {
            break;
        }

        for (int i = 0; i < count_of_std; i++)
        {
            if (strcmp(name, students[i]) == 0)
            {
                isFound = 1;
                index = i;
                break;
            }
        }
        if (isFound)
        {
            printf("Are you sure you want to permanently delete %s(y/n): ", name);
            scanf(" %c", &confirmation);

            if (confirmation == 'y')
            {

                for (int i = index; i < count_of_std - 1; i++)
                {
                    strcpy(students[i], students[i + 1]);
                }
                printf("%s deleted!\n\n", name);
                count_of_std--;
                break;
            }
            else
            {
                printf("Deletion cancelled\n");
            }
        }
        else
        {
            printf("Student is not present in the database\n");
        }

    } while (strcmp(name, "done") != 0);
}

void updateStudent(char students[1000][20])
{
    char name[20];
    char new_name[20];

    int index = 0;
    char confirmation;
    if (count_of_std == 0)
    {
        printf("No students available!\n\n");
        return;
    }
    do
    {
        int isFound = 0;

        printf("Enter the name of student you want to update(Enter done if done sarching): ");
        scanf(" %19s", name);

        if (strcmp(name, "done") == 0)
        {
            break;
        }

        for (int i = 0; i < count_of_std; i++)
        {
            if (strcmp(name, students[i]) == 0)
            {
                isFound = 1;
                index = i;
                break;
            }
        }
        if (isFound)
        {
            printf("Enter the new name: ");
            scanf(" %19s", new_name);

            printf("Are you sure? %s will be updated to %s! (y/n): ", name, new_name);
            scanf(" %c", &confirmation);

            if (confirmation == 'y')
            {
                strcpy(students[index], new_name);
                printf("Update successful\n\n");
                break;
            }
            else
            {
                printf("Update operation cancelled!\n");
            }
        }
        else
        {
            printf("Student is not present in the database\n");
        }

    } while (strcmp(name, "done") != 0);
}