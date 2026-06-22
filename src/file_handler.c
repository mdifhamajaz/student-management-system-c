#include <stdio.h>

#include "file_handler.h"
#include "student.h"
void loadFromFile(student students[1000])
{
    FILE *fptr;
    fptr = fopen("data/student_data.dat", "rb");

    if (fptr != NULL)
    {
        while (fread(&students[count_of_std], sizeof(student), 1, fptr) == 1)
        {
            count_of_std++;
        }

        fclose(fptr);
        fptr = NULL;
    } else {
        fptr = fopen("data/student_data.dat", "wb");
        fclose(fptr);
        fptr = NULL;
    }
     
}

void saveToFile(student students[1000])
{
    FILE *fptr;
    fptr = fopen("data/student_data.dat", "wb");

    if (fptr != NULL)
    {
        fwrite(students, sizeof(student), count_of_std, fptr);
         

        fclose(fptr);
        fptr = NULL;
    }
    else
    {
        printf("File not found!");
    }
}
