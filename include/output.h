#ifndef OUTPUT_H
#define OUTPUT_H

#include"student.h"

void printHeader(void);
void printSeparator(void);
void printStudentTable(student students[], int count);
void printTableMessage(const char *message);
void formatName(const char *src, char *dest, int width);


#endif