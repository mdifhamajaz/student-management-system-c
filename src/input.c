#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

void clearInputBuffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}
// TODO: this above function will be removed when all scanf converted to fgets.

void readString(const char *prompt, char *buffer, int size)
{
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

int readInt(const char *prompt)
{
    char str[34];
    char *endPtr;
    long value;

    while (1)
    {
        readString(prompt, str, sizeof(str));

        value = strtol(str, &endPtr, 10);

        if (endPtr != str && *endPtr == '\0')
        {
            return (int)value;
        }
        printf("Invalid input. Please try again.\n");
    }
}