#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
int main()
{
int status;
if ((status = system("date")) < 0)
perror("system() not found");
printf("end code %d\n", WEXITSTATUS(status));
if ((status = system("hello")) < 0)
perror("system() not found");
printf("end code %d\n", WEXITSTATUS(status));
if ((status = system("who; exit 44")) < 0)
perror("system() not found");
printf("end code %d\n", WEXITSTATUS(status));
}

