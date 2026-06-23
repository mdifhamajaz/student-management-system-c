#include <stdio.h>

void printMenu()
{

    printf("1: Add students\n");
    printf("2: Display students\n");
    printf("3: Search student By Name\n");
    printf("4: Search student By Roll\n");
    printf("5: Delete student\n");
    printf("6: Update student\n");
    printf("0: Exit\n");
}

int scanMenu()
{
    int choice;

    printf("Enter your choice serial no: ");
    scanf("%d", &choice);

    return choice;
}