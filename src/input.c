#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <float.h>

#include "input.h"

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
        errno = 0;
        value = strtol(str, &endPtr, 10);
        if (errno == ERANGE)
        {
            printf("Number out of range.\n");
            continue;
        }
        if (value > INT_MAX || value < INT_MIN)
        {
            printf("Number is outside int range.\n");
            continue;
        }
        if (endPtr != str && *endPtr == '\0')
        {
            return (int)value;
        }
        printf("Invalid input. Please try again.\n");
    }
}

float readFloat(const char *prompt)
{
    char str[34];
    char *endPtr;
    double value;

    while (1)
    {
        readString(prompt, str, sizeof(str));
        errno = 0;
        value = strtod(str, &endPtr);
        if (errno == ERANGE)
        {
            printf("Number out of range.\n");
            continue;
        }
        if (value > FLT_MAX || value < -FLT_MAX)
        {
            printf("Number is outside float range.\n");
            continue;
        }

        if (endPtr != str && *endPtr == '\0')
        {
            return (float)value;
        }
        printf("Invalid input. Please try again.\n");
    }
}