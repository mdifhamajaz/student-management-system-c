#include <string.h>

int isBackCommand(char *input){
    if(strcmp(input, "back") == 0) {
        return 1;
    }
    return 0;

}

int isExitCommand(char *input){
    if(strcmp(input, "exit") == 0) {
        return 1;
    }
    return 0;

}