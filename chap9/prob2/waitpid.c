#include <sys/types.h>

int main() {
    int pid1, pid2, child, status;

    printf("parental process start \n");
    pid1 = fork();

    if (pid1 == 0) {
        printf("child process [1] start \n");
        sleep(1);
        printf("child process [1] end \n");
        exit(1);
    }

    pid2 = fork();

    if (pid2 == 0) {
        printf("child process [2] start \n");
        sleep(2);
        printf("child process [2] end \n");
        exit(2);
    }

    child = waitpid(pid1, &status, 0);
    printf("child process [1] %d end \n", child);
    printf("\tend code %d\n", status >> 8);
}

