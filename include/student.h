


#ifndef STUDENT_H
#define STUDENT_H



typedef struct
{

    char name[34];
    int roll;
    float marks;
} student;

extern int count_of_std;
void addStudent(student students[1000]);
void displayStudents(student students[1000]);

#endif