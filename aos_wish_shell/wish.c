#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>


void printError(void) {
  char error_message[30] = "An error has occurred\n";
  write(STDERR_FILENO, error_message, strlen(error_message));
}

int main(int argc, char *argv[]) {
    bool isInteractive = false;
    FILE *input = NULL;

    if (argc == 1) {
        input = stdin;
        isInteractive = true;
    } else {

    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while (1) {
        if (isInteractive) {
            printf("wish>");
            
            read = getline(&line, &len, input);
            if (read == -1) {
                break;
            } else {
                // successfully read
                line[read - 1] = '\0'; // removed delimiter 
                printf("read %s\n", line);
            }

            if (strcmp(line, "exit") == 0) {
                exit(0);
            }

        }
    }

}