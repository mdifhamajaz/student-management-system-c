#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "input.h"
#include "command.h"
#include "student.h"

void printMainMenu()
{
    printf("==========================================\n");
    printf("1: Add students\n");
    printf("2: Display students\n");
    printf("3: Search student By Name\n");
    printf("4: Search student By Roll\n");
    printf("5: Delete student\n");
    printf("6: Update student\n");
    printf("7: Show toppers\n");
    printf("8: Show statistics\n");
    printf("0: Exit\n");
    printf("==========================================\n\n");
}

int scanMenu(student *students)
{
    char input[10];
    int choice;

    while (1)
    {
        readString("Enter your choice: ", input, sizeof(input));

        if (isExitCommand(input) || isBackCommand(input))
        {
            free(students);
            exit(EXIT_SUCCESS);
        }

        if (parseInt(input, &choice))
        {
            return choice;
        }

        printf("Invalid input. Please enter a number or a command(back/exit).\n");
    }
}

void printDisplayMenu()
{
    printf("==========================================\n");
    printf("             Display Students\n");
    printf("==========================================\n\n");
 
    printf("1: Original Order\n");
    printf("2: Marks (High to Low)\n");
    printf("3: Marks (Low to High)\n");
    printf("4: Name (A to Z)\n");
    printf("5: Name (Z to A)\n");
    printf("6: Roll Number (Ascending)\n");
    printf("0: Back\n");
    printf("==========================================\n\n");
}