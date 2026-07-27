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

void sortByMarksAscending(student *students)
{
    for (int i = 0; i < count_of_std; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < count_of_std; j++)
        {
            if (students[j].marks < students[minIndex].marks)
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            student temp = students[i];
            students[i] = students[minIndex];
            students[minIndex] = temp;
        }
    }
}