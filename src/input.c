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
    if (fgets(buffer, size, stdin) != NULL)
    {

        char *newline = strchr(buffer, '\n');
        if (newline != NULL)
        {
            *newline = '\0';
        }
        else
        {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
        }
    }
}

int parseInt(char *input, int *value)
{
    char *endPtr;
    long result;

    errno = 0;
    result = strtol(input, &endPtr, 10);

    if (errno == ERANGE || result > INT_MAX || result < INT_MIN)
        return 0;

    if (endPtr == input || *endPtr != '\0')
        return 0;

    *value = (int)result;
    return 1;
}

int parseFloat(char *input, float *value)
{
    char *endPtr;
    double result;

    errno = 0;
    result = strtod(input, &endPtr);
    if (errno == ERANGE || result > INT_MAX || result < INT_MIN)
        return 0;

    if (endPtr == input || *endPtr != '\0')
        return 0;

    *value = (float)result;
    return 1;
}
