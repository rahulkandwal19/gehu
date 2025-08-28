#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid1, pid2;

    // ---------------- Zombie Process ----------------
    pid1 = fork();
    if (pid1 == 0){
        printf("Zombie Child: PID=%d, Parent PID=%d\n", getpid(), getppid());
        exit(0);
    }

    else if (pid1 > 0){
        sleep(5);
    }

    else{
        printf("Fork for Zombie failed!\n");
    }

    //--------------Orphan process-----------------
    pid2 = fork();



    if (pid2 == 0){
        sleep(10);
        printf("Orphan Child: PID=%d, New Parent PID=%d\n", getpid(), getppid());
    }

    else if (pid2 > 0){
        printf("Parent (PID=%d) exiting, leaving orphan...\n", getpid());
        exit(0);
    }
    else
    {
        printf("Fork for Orphan failed!\n");
    }

    return 0;
}
