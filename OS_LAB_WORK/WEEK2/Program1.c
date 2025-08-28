#include <stdio.h>
#include <dirent.h>
#include<sys/wait.h>
int main(){
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");
    if (dir == NULL){
        perror("Directory Not found");
        return 0;
    }
    printf("Directory contents:\n");
    while ((entry = readdir(dir)) != NULL)  printf("%s\n", entry->d_name);
    closedir(dir);
    return 0;
}
