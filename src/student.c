#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "student.h"
#include "file_handler.h"
#include "input.h"
#include "output.h"
#include "command.h"
#include "sorting.h"
#include "ui.h"
#include "menu.h"

#define NAME_LENGTH 33
#define INITIAL_CAPACITY 10
#define PASS_MARKS 33

int count_of_std = 0;
int student_capacity = INITIAL_CAPACITY;

void addStudent(student **students)
{

    char name[NAME_LENGTH];

    do
    {
        if (count_of_std >= student_capacity)
        {
            student_capacity *= 2;
            student *temp = realloc(*students, student_capacity * sizeof(student));

            if (temp == NULL)
            {
                printf("Memory allocation failed.\n");
                free(*students);
                exit(EXIT_FAILURE);
            }

            *students = temp;
        }
        int toGoBack = 0;
        readString("Enter the name: ", name, sizeof(name));
        if (isBackCommand(name))
        {
            break;
        }

        if (isExitCommand(name))
        {
            free(*students);
            exit(EXIT_SUCCESS);
        }

        strcpy((*students)[count_of_std].name, name);
        int roll;
        char input[10];
        do
        {
            int isDuplicate = 0;
            readString("Enter the roll no: ", input, sizeof(input));

            if (isExitCommand(input))
            {
                free(*students);
                exit(EXIT_SUCCESS);
            }

            if (isBackCommand(input))
            {
                toGoBack = 1;
                break;
            }

            if (!parseInt(input, &roll))
            {
                printf("Invalid input. Please enter a valid number or command.\n");
            }
            else
            {

                if (roll < 1)
                {
                    printf("Roll no can't be negative or 0.\n");
                }
                else
                {

                    for (int i = 0; i < count_of_std; i++)
                    {
                        if ((*students)[i].roll == roll)
                        {
                            isDuplicate = 1;
                            printf("Roll already exists! Try again.\n");
                            break;
                        }
                    }

                    if (!isDuplicate)
                        break;
                }
            }
        } while (1);
        if (toGoBack)
        {
            break;
        }
        (*students)[count_of_std].roll = roll;
        do
        {
            float marks;
            readString("Enter his marks(%): ", input, sizeof(input));

            if (isExitCommand(input))
            {
                free(*students);
                exit(EXIT_SUCCESS);
            }
            if (isBackCommand(input))
            {
                toGoBack = 1;
                break;
            }

            if (!parseFloat(input, &marks))
            {
                printf("Invalid input. Please enter a valid marks or command.\n");
            }
            else
            {

                if (marks > 100 || marks < 0)
                {
                    printf("Marks must be between 0 to 100.\n");
                }
                else
                {
                    (*students)[count_of_std].marks = marks;
                    break;
                }
            }
        } while (1);
        if (toGoBack)
        {
            break;
        }

        count_of_std++;
        saveToFile(*students);

        printf("Added %s\n", name);
    } while (1);
}

void displayStudents(student *students)
{
    char name[NAME_LENGTH];

    if (count_of_std != 0)
    {

        int choice;
        do
        {
            printDisplayMenu();
            choice = scanMenu(students);
            if (choice == 0)
            {
                break;
            }
            
            if (choice > 6 || choice < 0)
            {
                printf("Invalid input\n");
                waitForEnter();
                continue;
            }
            student *sortedList = malloc(count_of_std * sizeof(student));
            if (choice > 1)
            {
                if (sortedList == NULL)
                {
                    printf("Memory allocation failed.\n");
                    return;
                }

                for (int i = 0; i < count_of_std; i++)
                {
                    sortedList[i] = students[i];
                }
            }

            if (choice == 1)
            {

                printHeader("S.No.");
                printStudentTable(students, count_of_std);
            }
            if (choice == 2)
            {
                sortByMarksDescending(sortedList, count_of_std);
                printHeader("S.No.");
                printStudentTable(sortedList, count_of_std);
            }
            if (choice == 3)
            {
                sortByMarksAscending(sortedList);
                printHeader("S.No.");
                printStudentTable(sortedList, count_of_std);
            }
            waitForEnter();

        } while (1);
    }
    else
    {
        printf("No students added yet!\n");
        waitForEnter();
    }
}

void searchStudentByName(student *students)
{
    char name[NAME_LENGTH];
    if (count_of_std == 0)
    {
        printf("No students available!\n");
        waitForEnter();
        return;
    }

    do
    {

        readString("Enter the name of student you want to search: ", name, sizeof(name));

        if (isBackCommand(name))
        {
            break;
        }

        if (isExitCommand(name))
        {
            free(students);
            exit(EXIT_SUCCESS);
        }

        student results[1000];
        int resultCount = 0;

        for (int i = 0; i < count_of_std; i++)
        {
            if (strcmp(name, students[i].name) == 0)
            {
                results[resultCount] = students[i];
                resultCount++;
            }
        }

        if (resultCount > 0)
        {
            printf("\nMatch Found:\n");
            printHeader("S.No.");
            printStudentTable(results, resultCount);
        }
        else
        {
            printf("No student found.\n");
        }

    } while (1);
}
void searchStudentByRoll(student *students)
{
    int roll;
    char input[10];
    if (count_of_std == 0)
    {
        printf("No students available!\n");
        waitForEnter();
        return;
    }

    do
    {
        int isFound = 0;

        readString("Enter the roll no. of student you want to search: ", input, sizeof(input));

        if (isExitCommand(input))
        {
            free(students);
            exit(EXIT_SUCCESS);
        }

        if (isBackCommand(input))
        {
            break;
        }

        if (!parseInt(input, &roll))
        {
            printf("Invalid input. Please enter a valid number or command.\n");
        }
        else
        {
            if (roll < 1)
            {
                printf("Roll no can't be negative or 0.\n");
            }
            else
            {

                for (int i = 0; i < count_of_std; i++)
                {
                    if (roll == students[i].roll)
                    {

                        printf("\nStudent Found:\n");
                        printHeader("S.No.");
                        printStudentTable(&students[i], 1);
                        isFound = 1;
                        break;
                    }
                }
                if (!isFound)
                {
                    printf("No student found.\n");
                }
            }
        }

    } while (1);
}

void deleteStudent(student *students)
{
    int roll;
    char input[10];
    char confirmation[10];
    int index = 0;
    if (count_of_std == 0)
    {
        printf("No students available!\n");
        waitForEnter();
        return;
    }

    do
    {
        int isFound = 0;
        readString("Enter the roll no. of student you want to delete: ", input, sizeof(input));

        if (isExitCommand(input))
        {
            free(students);
            exit(EXIT_SUCCESS);
        }

        if (isBackCommand(input))
        {
            break;
        }

        if (!parseInt(input, &roll))
        {
            printf("Invalid input. Please enter a valid number or command.\n");
        }
        else
        {
            if (roll < 1)
            {
                printf("Roll no can't be negative or 0.\n");
            }
            else
            {

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
                    printTableMessage("Confirm Deletion");
                    printf("The following student will be deleted:\n\n");

                    printHeader("S.No.");
                    printStudentTable(&students[index], 1);

                    readString("\nDelete this student?\nType 'yes' to confirm or 'no' to cancel\n>", confirmation, sizeof(confirmation));

                    if (isExitCommand(confirmation))
                    {
                        free(students);
                        exit(EXIT_SUCCESS);
                    }

                    if (isBackCommand(confirmation))
                    {
                        break;
                    }

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
            }
        }

    } while (1);
}

void updateStudent(student *students)
{
    int roll;
    char new_name[NAME_LENGTH];
    int new_roll;
    float new_marks;
    char input[10];

    int index = 0;
    char confirmation[10];
    if (count_of_std == 0)
    {
        printf("No students available!\n");
        waitForEnter();
        return;
    }
    do
    {
        int toGoBack = 0;
        int isFound = 0;
        readString("Enter the roll no. of student you want to update: ", input, sizeof(input));

        if (isExitCommand(input))
        {
            free(students);
            exit(EXIT_SUCCESS);
        }

        if (isBackCommand(input))
        {

            break;
        }

        if (!parseInt(input, &roll))
        {
            printf("Invalid input. Please enter a valid number or command.\n");
        }
        else
        {

            if (roll < 1)
            {
                printf("Roll no can't be negative or 0.\n");
            }
            else
            {
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
                    printHeader("S.No.");
                    printStudentTable(&students[index], 1);

                    readString("Enter the new name: ", new_name, sizeof(new_name));

                    if (isExitCommand(new_name))
                    {
                        free(students);
                        exit(EXIT_SUCCESS);
                    }

                    if (isBackCommand(new_name))
                    {

                        break;
                    }

                    do
                    {
                        int isDuplicate = 0;

                        readString("Enter the new roll no: ", input, sizeof(input));

                        if (isExitCommand(input))
                        {
                            free(students);
                            exit(EXIT_SUCCESS);
                        }

                        if (isBackCommand(input))
                        {
                            toGoBack = 1;
                            break;
                        }

                        if (!parseInt(input, &new_roll))
                        {
                            printf("Invalid input. Please enter a valid number or command.\n");
                        }
                        else
                        {

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
                                {
                                    break;
                                }
                            }
                        }

                    } while (1);

                    if (toGoBack)
                    {
                        break;
                    }

                    do
                    {

                        readString("Enter the new marks(%): ", input, sizeof(input));

                        if (isExitCommand(input))
                        {
                            free(students);
                            exit(EXIT_SUCCESS);
                        }
                        if (isBackCommand(input))
                        {
                            toGoBack = 1;
                            break;
                        }

                        if (!parseFloat(input, &new_marks))
                        {
                            printf("Invalid input. Please enter a valid marks or command.\n");
                        }
                        else
                        {

                            if (new_marks > 100 || new_marks < 0)
                            {
                                printf("Marks must be between 0 to 100.\n");
                            }
                            else
                            {
                                break;
                            }
                        }
                    } while (1);
                    if (toGoBack)
                    {
                        break;
                    }

                    printTableMessage("Confirm Update");

                    printf("OLD DATA:\n");
                    printHeader("S.No.");
                    printStudentTable(&students[index], 1);

                    student newData;
                    strcpy(newData.name, new_name);
                    newData.marks = new_marks;
                    newData.roll = new_roll;

                    printf("\nNEW DATA:\n");
                    printHeader("S.No.");
                    printStudentTable(&newData, 1);

                    readString("\nUpdate this student details?\nType 'yes' to confirm or 'no' to cancel\n>", confirmation, sizeof(confirmation));
                    if (isExitCommand(confirmation))
                    {
                        free(students);
                        exit(EXIT_SUCCESS);
                    }

                    if (isBackCommand(confirmation))
                    {
                        break;
                    }
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
            }
        }
    } while (1);
}

void showToppers(student *students)
{
    if (count_of_std != 0)
    {
        int topCount = 3;
        if (topCount > count_of_std)
        {
            topCount = count_of_std;
        }
        student *topperList = malloc(count_of_std * sizeof(student));
        if (topperList == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }

        for (int i = 0; i < count_of_std; i++)
        {
            topperList[i] = students[i];
        }

        sortByMarksDescending(topperList, topCount);

        printf("==========================================\n");
        printf("              Top Performers\n");
        printf("==========================================\n\n");
        printHeader("Rank");
        printStudentTable(topperList, topCount);

        free(topperList);
    }
    else
    {
        printf("No students added yet!\n");
    }
    waitForEnter();
}

void showStatistics(student *students)
{
    if (count_of_std != 0)
    {
        int totalStudents = count_of_std;
        float highestMarks = students[0].marks;
        char highestStudentName[NAME_LENGTH];
        strcpy(highestStudentName, students[0].name);
        float lowestMarks = students[0].marks;
        char lowestStudentName[NAME_LENGTH];
        strcpy(lowestStudentName, students[0].name);
        float totalMarks = 0;
        int passCount = 0;
        int failCount = 0;
        float passPercent = 0;
        float failPercent = 0;

        for (int i = 0; i < totalStudents; i++)
        {
            if (students[i].marks > highestMarks)
            {
                highestMarks = students[i].marks;
                strcpy(highestStudentName, students[i].name);
            }

            if (students[i].marks < lowestMarks)
            {
                lowestMarks = students[i].marks;
                strcpy(lowestStudentName, students[i].name);
            }

            totalMarks += students[i].marks;

            if (students[i].marks >= PASS_MARKS)
            {
                passCount++;
            }
        }
        float averageMarks = totalMarks / totalStudents;

        failCount = totalStudents - passCount;

        passPercent = ((float)passCount / totalStudents) * 100;

        failPercent = 100 - passPercent;

        char displayHighest[15];
        char displayLowest[15];

        formatName(highestStudentName, displayHighest, 14);
        formatName(lowestStudentName, displayLowest, 14);

        printf("==========================================\n");
        printf("                Statistics\n");
        printf("==========================================\n\n");

        printf("Total Students   : %d\n\n", totalStudents);

        printf("Highest Marks    : %.2f (%s)\n", highestMarks, displayHighest);
        printf("Lowest Marks     : %.2f (%s)\n\n", lowestMarks, displayLowest);

        printf("Average Marks    : %.2f\n\n", averageMarks);

        printf("Passed Students  : %d\n", passCount);
        printf("Failed Students  : %d\n\n", failCount);

        printf("Pass Percentage  : %.2f%%\n", passPercent);
        printf("Fail Percentage  : %.2f%%\n", failPercent);

        printf("\n==========================================\n\n");
    }
    else
    {
        printf("No students added yet!\n");
    }
    waitForEnter();
}
