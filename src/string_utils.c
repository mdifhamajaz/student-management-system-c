#include <ctype.h>

void toLowerCase(const char *src, char *dest)
{
    while (*src)
    {
        *dest = tolower((unsigned char)*src);
        src++;
        dest++;
    }

    *dest = '\0';
}