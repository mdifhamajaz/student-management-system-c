#include <stdio.h>
#include <string.h>

#include "input.h"

void clearInputBuffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF);
}
//TODO: this above function will be removed when all scanf converted to fgets.
 

void readString(const char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}