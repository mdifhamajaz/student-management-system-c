#include <stdio.h>
#include<string.h>

#include "output.h"
#include "student.h"

void printHeader(void)
{
    printSeparator();
    printf("| %-5s | %-4s | %-14s | %-6s |\n", "S.No.", "Roll", "Name", "Marks");
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
        printf("| %-5d | %-4d | %-14s | %-6.2f |\n",
               i + 1,
               students[i].roll,
               students[i].name,
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

    for (int i = 1; i < padding; i++){
        printf("-");
    }
    printf(" ");
    printf("%s", message);
    printf(" ");
    if(len % 2 != 0){
        padding-=1;
    }  
    for (int i = 1; i < padding; i++){
        printf("-");
    }
    printf("\n");
}