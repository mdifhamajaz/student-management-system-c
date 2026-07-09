#include <stdio.h>
#include <string.h>

#include "file_handler.h"
#include "student.h"
#include "menu.h"
#include "input.h"
#include "ui.h"

int main()
{
    printWelcome();
    waitForEnter();
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
