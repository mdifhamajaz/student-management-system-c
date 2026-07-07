#ifndef INPUT_H
#define INPUT_H

void clearInputBuffer(void); //TODO: remove after scanf changed to fgets
void readString(const char *prompt, char *buffer, int size);
int readInt(const char *prompt);


#endif