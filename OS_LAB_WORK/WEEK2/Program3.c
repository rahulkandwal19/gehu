#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 0;
    }
    else if (pid == 0)
    {
        execlp("ls", "ls", "-l", NULL);
        perror("execlp failed");
        return 0;
    }
    else
    {
        wait(NULL);
        printf("Child process finished\n");
    }
    return 0;
}
