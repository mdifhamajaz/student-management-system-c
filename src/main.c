#include <stdio.h>
#include <string.h>

#include "file_handler.h"
#include "student.h"
#include "menu.h"






void searchStudentByName(student students[1000]);
void searchStudentByRoll(student students[1000]);
void deleteStudent(student students[1000]);
void updateStudent(student students[1000]);


int main()
{
    student students[1000];

    loadFromFile(students);

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
            searchStudentByName(students);
        }
        if (choice == 4)
        {
            searchStudentByRoll(students);
        }
        if (choice == 5)
        {
            deleteStudent(students);
        }
        if (choice == 6)
        {
            updateStudent(students);
        }

    } while (choice != 0);

    return 0;
}






void searchStudentByName(student students[1000])
{
    char name[34];
    if (count_of_std == 0)
    {
        printf("No students available!\n\n");
        return;
    }

    do
    {
        int isFound = 0;

        printf("Enter the name of student you want to search(Enter done if done sarching): ");
        scanf(" %33s", name);

        if (strcmp(name, "done") == 0)
        {
            break;
        }

        for (int i = 0; i < count_of_std; i++)
        {
            if (strcmp(name, students[i].name) == 0)
            {
                printf("\nMatch Found:\n");
                printf("Name : %s\n", students[i].name);
                printf("Roll : %d\n", students[i].roll);
                printf("Marks: %.2f %%\n", students[i].marks);

                isFound = 1;
            }
        }

        if (!isFound)
        {
            printf("No student found with this name\n");
        }
    } while (strcmp(name, "done") != 0);
}
void searchStudentByRoll(student students[1000])
{
    int roll;
    if (count_of_std == 0)
    {
        printf("No students available!\n\n");
        return;
    }

    do
    {
        int isFound = 0;

        printf("Enter the roll no. of student you want to search(Enter 0 if done sarching): ");
        scanf("%d", &roll);

        if (roll == 0)
        {
            break;
        }

        for (int i = 0; i < count_of_std; i++)
        {
            if (roll == students[i].roll)
            {
                printf("\nMatch Found:\n");
                printf("Name : %s\n", students[i].name);
                printf("Roll : %d\n", students[i].roll);
                printf("Marks: %.2f %%\n", students[i].marks);

                isFound = 1;
            }
        }

        if (!isFound)
        {
            printf("No student found with this roll no.\n");
        }
    } while (roll != 0);
}
void deleteStudent(student students[1000])
{
    int roll;
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
        printf("Enter the roll no. of student to delete(Enter 0 if done deleting): ");
        scanf("%d", &roll);

        if (roll == 0)
        {
            break;
        }

        for (int i = 0; i < count_of_std; i++)
        {
            if (roll == students[i].roll)
            {
                isFound = 1;
                index = i;
                break;
            }
        }
        if (isFound)
        {
            printf("\n----- Confirm Deletion -----\n");

            printf("STUDENT DATA:\n");
            printf("Name : %s\n", students[index].name);
            printf("Roll : %d\n", students[index].roll);
            printf("Marks: %.2f %%\n", students[index].marks);

            printf("\nConfirm Deletion? (y/n): ");
            scanf(" %c", &confirmation);

            if (confirmation == 'y')
            {

                for (int i = index; i < count_of_std - 1; i++)
                {
                    students[i] = students[i + 1];
                }
                printf("Deletion successful\n");
                count_of_std--;
                saveToFile(students);
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

    } while (roll != 0);
}

void updateStudent(student students[1000])
{
    int roll;
    char new_name[34];
    int new_roll;
    float new_marks;

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

        printf("Enter the roll no. of student you want to update(Enter 0 if done sarching): ");
        scanf("%d", &roll);

        if (roll == 0)
        {
            break;
        }

        for (int i = 0; i < count_of_std; i++)
        {
            if (roll == students[i].roll)
            {
                isFound = 1;
                index = i;
                break;
            }
        }
        if (isFound)
        {
            printf("OLD DATA:\n");
            printf("Name : %s\n", students[index].name);
            printf("Roll : %d\n", students[index].roll);
            printf("Marks: %.2f %%\n", students[index].marks);
            printf("Enter the new name: ");
            scanf(" %33s", new_name);

            do
            {
                int isDuplicate = 0;

                printf("Enter the new roll no: ");
                scanf("%d", &new_roll);

                if (new_roll < 1)
                {
                    printf("Roll no can't be negative or 0.\n");
                }
                else
                {

                    for (int i = 0; i < count_of_std; i++)
                    {
                        if (students[i].roll == new_roll && i != index)
                        {
                            isDuplicate = 1;
                            printf("Roll already exists! Try again.\n");
                            break;
                        }
                    }

                    if (!isDuplicate)
                        break;
                }

            } while (1);

            printf("Enter the new marks(%%): ");
            scanf("%f", &new_marks);

            printf("\n----- Confirm Update -----\n");

            printf("OLD DATA:\n");
            printf("Name : %s\n", students[index].name);
            printf("Roll : %d\n", students[index].roll);
            printf("Marks: %.2f %%\n", students[index].marks);

            printf("\nNEW DATA:\n");
            printf("Name : %s\n", new_name);
            printf("Roll : %d\n", new_roll);
            printf("Marks: %.2f %%\n", new_marks);

            printf("\nConfirm update? (y/n): ");
            scanf(" %c", &confirmation);

            if (confirmation == 'y')
            {
                strcpy(students[index].name, new_name);
                students[index].roll = new_roll;
                students[index].marks = new_marks;
                printf("Update successful\n\n");
                saveToFile(students);
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

    } while (roll != 0);
}