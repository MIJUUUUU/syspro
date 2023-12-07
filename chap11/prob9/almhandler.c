#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

volatile int elapsedSeconds = 0;

void alarmHandler(int signo) {
    printf("Wake up\n");
    exit(0);
}

typedef void (*sighandler_t)(int);

sighandler_t my_signal(int signo, sighandler_t handler) {
    struct sigaction newact, oldact;

    newact.sa_handler = handler;
    newact.sa_flags = 0;
    sigemptyset(&newact.sa_mask);

    if (sigaction(signo, &newact, &oldact) < 0) {
        return SIG_ERR;
    }

    return oldact.sa_handler;
}

int main() {
    my_signal(SIGALRM, alarmHandler);
    alarm(5);

    while (1) {
        sleep(1);
        elapsedSeconds++;
        printf("%d second\n", elapsedSeconds);
    }

    printf("Not Executed\n");

    return 0;
}

