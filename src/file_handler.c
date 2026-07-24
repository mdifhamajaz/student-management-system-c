#include <stdio.h>
#include <stdlib.h>

#include "file_handler.h"
#include "student.h"
void loadFromFile(student *students)
{
    FILE *fptr;
    fptr = fopen("data/student_data.dat", "rb");

    if (fptr != NULL)
    {
        while (fread(&students[count_of_std], sizeof(student), 1, fptr) == 1)
        {
            count_of_std++;
            if (count_of_std >= student_capacity)
            {
                student_capacity *= 2;
                student *temp = realloc(students, student_capacity * sizeof(student));

                if (temp == NULL)
                {
                    printf("Memory allocation failed.\n");
                    free(students);
                    exit(EXIT_FAILURE);
                }

                students = temp;
            }
        }

        fclose(fptr);
        fptr = NULL;
    }
    else
    {
        fptr = fopen("data/student_data.dat", "wb");
        fclose(fptr);
        fptr = NULL;
    }
}

void saveToFile(student *students)
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
