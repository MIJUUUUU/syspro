#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;

    while ((opt = getopt(argc, argv, "e:ugip")) != -1) {
        switch (opt) {
            case 'e':
                if (getenv(optarg) != NULL) {
                    printf("%s=%s\n", optarg, getenv(optarg));
                } else {
                    printf("Environment variable '%s' does not exist.\n", optarg);
                }
                break;

            case 'u':
                printf("My Realistic User ID: %d\n", getuid());
                printf("My Valid User ID: %d\n", geteuid());
                break;

            case 'g':
                printf("My Realistic Group ID: %d\n", getgid());
                printf("My Valid Group ID: %d\n", geteuid());
                break;

            case 'i':
                printf("My Process Number: %d\n", getpid());
                break;

            case 'p':
                printf("My Parent's Process Number: %d\n", getppid());
                break;

            default:
                fprintf(stderr, "Usage: %s [-e environment_variable] [-u] [-g] [-i] [-p]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    return 0;
}

