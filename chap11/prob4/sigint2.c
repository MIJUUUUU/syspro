#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct sigaction newact;
struct sigaction oldact;

void sigint_handler(int signo);

int main(void) {
    newact.sa_handler = sigint_handler;
    newact.sa_flags = 0;
    sigaction(SIGINT, &newact, &oldact);

    while (1) {
        printf("Type Ctrl-C!\n");
        sleep(1);
    }

    return 0;
}

void sigint_handler(int signo) {
    printf("Signal number %d\n", signo);
    printf("Press it again to exit.\n");
    sigaction(SIGINT, &oldact, NULL);
}

