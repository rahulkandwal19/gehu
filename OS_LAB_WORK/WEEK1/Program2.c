#include <stdio.h>
#include <unistd.h>
int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
    }
    else if (pid == 0)
    {
        printf("Child Process:-\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
        sleep(1);
    }
    else
    {
        printf("Parent Process:-\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
        sleep(1);
    }
    return 0;}
