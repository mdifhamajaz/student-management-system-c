#include<stdio.h>
#include<string.h>


#include "student.h"
#include "file_handler.h"
int count_of_std = 0;

void addStudent(student students[1000])
{

    char name[34];

    do
    {
        printf("Enter the name of student to add(Enter done if done adding): ");
        scanf(" %33s", name);

        if (strcmp(name, "done") == 0)
        {
            break;
        }
        strcpy(students[count_of_std].name, name);
        int roll;
        do
        {
            int isDuplicate = 0;

            printf("Enter the roll no: ");
            scanf("%d", &roll);

            if (roll < 1)
            {
                printf("Roll no can't be negative or 0.\n");
            }
            else
            {

                for (int i = 0; i < count_of_std; i++)
                {
                    if (students[i].roll == roll)
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

        students[count_of_std].roll = roll;

        printf("Enter his marks(%%): ");
        scanf("%f", &(students[count_of_std].marks));

        count_of_std++;
        saveToFile(students);

        printf("Added %s\n", name);
    } while (strcmp(name, "done") != 0);
}

void displayStudents(student students[1000])
{
    char name[34];

    do
    {
        if (count_of_std != 0)
        {
            for (int i = 0; i < count_of_std; i++)
            {
                printf("%d: Name: %s\n", i + 1, students[i].name);
                printf("   Roll: %d\n", students[i].roll);
                printf("   Marks: %.2f %%\n", students[i].marks);
            }
        }
        else
        {
            printf("No students added yet!\n");
        }
        printf("\nEnter done to go to main menu: ");
        scanf(" %33s", name);
    } while (strcmp(name, "done") != 0);
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