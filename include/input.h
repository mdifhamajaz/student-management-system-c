#ifndef INPUT_H
#define INPUT_H

void readString(const char *prompt, char *buffer, int size);
int parseInt(char *input, int *value);
int parseFloat(char *input, float *value);


#endif