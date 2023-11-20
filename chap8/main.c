#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <option>\n", argv[0]);
        return 1;
    }

    char *selectedOption = argv[1];

    if (strcmp(selectedOption, "-e") == 0) {
        if (argc < 3) {
            char **environmentVariables;
            extern char **environ;

            for (environmentVariables = environ; *environmentVariables != 0; environmentVariables++) {
                char *equalSign = strchr(*environmentVariables, '=');

                if (equalSign != NULL) {
                    printf("%s\n", equalSign + 1);
                } else {
                    printf("%s\n", *environmentVariables);
                }
            }
        } else {
            char *envName = argv[2];
            char *envValue = getenv(envName);

            if (envValue != NULL) {
                printf(envName);
                printf(" = ");
                printf("%s\n", envValue);
            } else {
                printf("not found : %s\n", envName);
                return 1;
            }
        }
    } 
    else if (strcmp(selectedOption, "-u") == 0) 
    {
        printf("My Realistic User ID : %d(%s) \n", getuid(), getpwuid(getuid())->pw_name);
        printf("My Valid User ID : %d(%s) \n", geteuid(), getpwuid(geteuid())->pw_name);
    } 
    else if (strcmp(selectedOption, "-g") == 0)
    {
        printf("My Realistic Group ID : %d(%s) \n", getgid(), getgrgid(getgid()) -> gr_name);
        printf("My Valid Group ID : %d(%s) \n", getegid(), getgrgid(getegid()) -> gr_name);
    }
    else if (strcmp(selectedOption, "-i") == 0)
    {
        printf("My Process Number : [%d] \n", getpid());
    }
    else if (strcmp(selectedOption, "-p") == 0)
    {
        printf("My Parent Process Number : [%d] \n", getppid());
    }
    return 0;
}

