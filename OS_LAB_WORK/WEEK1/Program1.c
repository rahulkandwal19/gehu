#include <stdio.h>
#include <unistd.h>
int main(){
    pid_t pid = fork();
    if (pid < 0){
        perror("fork failed");
    }
    else if (pid == 0){
        printf("This is child process\n");
    }
    else{
        printf("This is parent process with pid: %d.\n",getpid());
    }
    return 0;
