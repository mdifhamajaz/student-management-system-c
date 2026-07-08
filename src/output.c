#include <stdio.h>

#include "output.h"
#include "student.h"

void printHeader(void)
{
    printSeparator();
    printf("| %-5s | %-4s | %-13s | %-6s |\n", "S.No.", "Roll", "Name", "Marks");
    printSeparator();
}

void printSeparator(void)
{
    printf("+-------+------+---------------+--------+\n");
}

void printStudentTable(student students[], int count, int startIndex)
{
    for (int i = 0; i < count; i++)
    {
        printf("| %-5d | %-4d | %-13s | %-6.2f |\n",
               startIndex + i + 1,
               students[i].roll,
               students[i].name,
               students[i].marks);
    }

    printSeparator();
}