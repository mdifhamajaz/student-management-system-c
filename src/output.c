#include <stdio.h>
#include <string.h>

#include "output.h"
#include "student.h"

void printHeader(const char *firstColumn)
{
    printSeparator();
    printf("| %-5s | %-4s | %-14s | %-6s |\n", firstColumn, "Roll", "Name", "Marks");
    printSeparator();
}

void printSeparator(void)
{
    printf("+-------+------+----------------+--------+\n");
}

void printStudentTable(student students[], int count)
{
    for (int i = 0; i < count; i++)
    {
        char displayName[15];
        formatName(students[i].name, displayName, 14);
        printf("| %-5d | %-4d | %-14s | %-6.2f |\n",
               i + 1,
               students[i].roll,
               displayName,
               students[i].marks);
    }

    printSeparator();
}

void printTableMessage(const char *message)
{
    int width = 43;
    int len = strlen(message);

    int padding = (width - len) / 2;

    printf("\n");

    for (int i = 1; i < padding; i++)
    {
        printf("-");
    }
    printf(" ");
    printf("%s", message);
    printf(" ");
    if (len % 2 != 0)
    {
        padding -= 1;
    }
    for (int i = 1; i < padding; i++)
    {
        printf("-");
    }
    printf("\n");
}

void formatName(const char *src, char *dest, int width)
{
    if (strlen(src) > 14)
    {
        strncpy(dest, src, 12);
        dest[12] = '\0';
        strcat(dest, "..");
    }
    else
    {
        strcpy(dest, src);
    }
}