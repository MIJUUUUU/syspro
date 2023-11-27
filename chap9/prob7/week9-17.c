#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARG_LENGTH 100
#define MAX_INPUT_LENGTH 1024

int main() {
    char input[MAX_INPUT_LENGTH];
    char *token;
    char *args[MAX_ARG_LENGTH];
    int background;

    while (1) {
        printf("Pls input cmd: ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("Error reading input");
            exit(EXIT_FAILURE);
        }

        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0)
            continue;

        background = 0;
        if (input[strlen(input) - 1] == '&') {
            background = 1;
            input[strlen(input) - 1] = '\0';
        }

        pid_t pid = fork();

        if (pid == 0) {
            token = strtok(input, " ");
            int i = 0;

            while (token != NULL) {
                args[i++] = token;
                token = strtok(NULL, " ");
            }

            args[i] = NULL;

            if (execvp(args[0], args) == -1) {
                perror("Execution failed");
                exit(EXIT_FAILURE);
            }
        } else if (pid > 0) {
            if (!background) {
                int status;
                waitpid(pid, &status, 0);
            }
        } else {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }

        printf("[%d] Parent process start\n", getpid());
    }

    return 0;
}

