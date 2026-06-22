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