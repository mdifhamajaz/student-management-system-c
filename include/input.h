#ifndef INPUT_H
#define INPUT_H

void readString(const char *prompt, char *buffer, int size);
int parseInt(char *input, int *isValid);
int readInt(const char *prompt);
float readFloat(const char *prompt);


#endif