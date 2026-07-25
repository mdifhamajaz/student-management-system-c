

#ifndef STUDENT_H
#define STUDENT_H



typedef struct
{

    char name[33];
    int roll;
    float marks;
} student;

extern int count_of_std;
extern int student_capacity;
void addStudent(student **students);
void displayStudents(student *students);
void searchStudentByName(student *students);
void searchStudentByRoll(student *students);
void deleteStudent(student *students);
void updateStudent(student *students);
void showToppers(student *students);

#endif