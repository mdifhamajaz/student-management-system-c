#include <string.h>
#include <stdio.h>

void printWelcome(void) {
    printf("==========================================\n");
    printf("        Student Management System\n");
    printf("==========================================\n\n");

    printf("Global Commands:\n");
    printf("  back - Return to previous menu\n");
    printf("  exit - Exit the application\n\n");

 

}

void waitForEnter(void) {
    char buffer[10];

    printf("Press Enter to continue...");
    fgets(buffer, sizeof(buffer), stdin);
}
 