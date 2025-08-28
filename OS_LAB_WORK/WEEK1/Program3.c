#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t cpid1, cpid2;
    cpid1 = fork();

    if (cpid1 < 0){
        perror("Fork failed");
        exit(1);
    }

    if (cpid1 == 0)  {
        printf("First Child with PID: %d, Parent with PID : %d\n", getpid(), getppid());
        sleep(2);
        printf("First Child completed\n");
        exit(0);
    }

    else{
        wait(NULL);
        printf("First child finished execution.\n");
        cpid2 = fork();


        if (cpid2 < 0){
            perror("Fork failed");
            exit(1);
        }
        if (cpid2 == 0){
            printf("Second Child with PID: %d,  Parent with PID: %d\n", getpid(), getppid());
            sleep(5);
            printf("Second Child PID: %d, still running, now Parent PID: %d\n", getpid(), 
getppid());
            exit(0);
        }
        else  {
            printf("Parent exits before second child completes!\n");
            exit(0);
        }
    }
}
