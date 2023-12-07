#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

volatile int elapsedSeconds = 0;

void alarmHandler(int signo) {
    printf("Wake up\n");
    exit(0);
}

int main() {
    signal(SIGALRM, alarmHandler);
    alarm(5);

    while (1) {
        sleep(1);
        elapsedSeconds++;
        printf("%d second\n", elapsedSeconds);
    }

    printf("Not Executed\n");

    return 0;
}

