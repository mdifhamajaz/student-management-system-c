#include <stdio.h>

#include "menu.h"
#include "input.h"

void printMenu()
{
    printf("==========================================\n");
    printf("1: Add students\n");
    printf("2: Display students\n");
    printf("3: Search student By Name\n");
    printf("4: Search student By Roll\n");
    printf("5: Delete student\n");
    printf("6: Update student\n");
    printf("0: Exit\n");
    printf("==========================================\n\n");
}

int scanMenu()
{
    int choice;

    choice = readInt("Enter your choice: ");

    return choice;
}