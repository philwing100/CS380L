#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>


void printError(void) {
  char error_message[30] = "An error has occurred\n";
  write(STDERR_FILENO, error_message, strlen(error_message));
}

char **addPath(char **path, char *inputPath) {
    printf("a");
    // if (path) {
    //     for (int i = 0; path[i]; i++) {
    //         free(path[i]);
    //     }
    //     free(path);
    // }
printf("b");    
    // char **newPath = NULL;

    char *token = strtok(inputPath, " ");
    int currentPathCount = 0;
printf("c");
    while (token != NULL) {
        printf("d");
        char **tempArray = realloc(path, sizeof(char *) * (currentPathCount + 2));
        
        path = tempArray;
        path[currentPathCount] = strdup(token);
        currentPathCount++;
        printf("added: %s\n", token);
        printf(path[currentPathCount]);

        token = strtok(inputPath, " ");
    }

    return path;
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
    size_t read;

    char **paths = {"/add", "/dasdasdb"};


    while (1) {
        if (isInteractive) {
            printf("wish>");
            
            read = getline(&line, &len, input);
            if (read == -1) {
                break;
            } else {
                line[read - 1] = '\0';
                printf("read %s\n", line);
            }

            if (strstr(line, "path") != NULL) {
                printf("%d \n", access("/home/ashang/utexas/CS380L/aos_wish_shell", X_OK));
                addPath(paths, "/a /b");
            }


            if (strstr(line, "exit") != NULL && read == 5) {
                exit(0);
            } else if (strstr(line, "exit") != NULL && read != 5) {
                printError();
            }

        }
    }

}