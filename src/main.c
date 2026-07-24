#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "file_handler.h"
#include "student.h"
#include "menu.h"
#include "input.h"
#include "ui.h"

int main()
{
    printWelcome();
    waitForEnter();
    student *students = malloc(student_capacity * sizeof(student));

    loadFromFile(students);
    int choice;

    do
    {
        printMenu();
        choice = scanMenu();

        if (choice == 1)
        {

            addStudent(students);
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

    free(students);
    students = NULL;

    return 0;
}
