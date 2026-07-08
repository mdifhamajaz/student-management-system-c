#include <stdio.h>
#include <string.h>

#include "student.h"
#include "file_handler.h"
#include "input.h"
int count_of_std = 0;

void addStudent(student students[1000])
{

    char name[34];

    do
    {
        readString("Enter the name of student to add(Enter done if done adding): ", name, 33);

        if (strcmp(name, "done") == 0)
        {
            break;
        }
        strcpy(students[count_of_std].name, name);
        int roll;
        do
        {
            int isDuplicate = 0;

            roll = readInt("Enter the roll no: ");

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
        do
        {
            float marks = readFloat("Enter his marks(%): ");
            if (marks > 100 || marks < 0)
            {
                printf("Marks must be between 0 to 100.\n");
            }
            else
            {
                students[count_of_std].marks = marks;
                break;
            }
        } while (1);

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
        readString("\nEnter done to go to main menu: ", name, 33);
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

        readString("Enter the name of student you want to search(Enter done if done sarching): ", name, 33);

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

        roll = readInt("Enter the roll no. of student you want to search(Enter 0 if done searching): ");

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
    char confirmation[10];
    int index = 0;
    if (count_of_std == 0)
    {
        printf("No students available!\n\n");
        return;
    }

    do
    {
        int isFound = 0;
        roll = readInt("Enter the roll no. of student you want to delete(Enter 0 if done deleting): ");

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

            readString("\nDelete this student?\nType 'yes' to confirm or 'no' to cancel\n>", confirmation, sizeof(confirmation));

            if (strcmp(confirmation, "yes") == 0)
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
    char confirmation[10];
    if (count_of_std == 0)
    {
        printf("No students available!\n\n");
        return;
    }
    do
    {
        int isFound = 0;

        roll = readInt("Enter the roll no. of student you want to update(Enter 0 if done updating): ");

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

            readString("Enter the new name: ", new_name, 33);

            do
            {
                int isDuplicate = 0;

                new_roll = readInt("Enter the new roll no: ");

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

            do
            {
                new_marks = readFloat("Enter the new marks(%): ");
                if (new_marks > 100 || new_marks < 0)
                {
                    printf("Marks must be between 0 to 100.\n");
                }
                else
                {
                    break;
                }
            } while (1);

            printf("\n----- Confirm Update -----\n");

            printf("OLD DATA:\n");
            printf("Name : %s\n", students[index].name);
            printf("Roll : %d\n", students[index].roll);
            printf("Marks: %.2f %%\n", students[index].marks);

            printf("\nNEW DATA:\n");
            printf("Name : %s\n", new_name);
            printf("Roll : %d\n", new_roll);
            printf("Marks: %.2f %%\n", new_marks);

          

             readString("\nUpdate this student details?\nType 'yes' to confirm or 'no' to cancel\n>", confirmation, sizeof(confirmation));

            if (strcmp(confirmation, "yes") == 0)
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