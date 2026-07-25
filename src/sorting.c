#include "sorting.h"

void sortByMarksDescending(student *students, int topCount)
{
    for (int i = 0; i < topCount; i++)
    {
        int maxIndex = i;

        for (int j = i + 1; j < count_of_std; j++)
        {
            if (students[j].marks > students[maxIndex].marks)
            {
                maxIndex = j;
            }
        }

        if (maxIndex != i)
        {
            student temp = students[i];
            students[i] = students[maxIndex];
            students[maxIndex] = temp;
        }
    }
}