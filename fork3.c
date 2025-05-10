// before terminating, the parent waits for the child to finish its task
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // int pid;
    // pid = fork();
    pid_t pid = fork();
    if(pid < 0){
        return 0;
        printf("\nError");
        exit(1);
    }else if(pid == 0){
        printf("\n Hello I am child process ");
        printf("\n My pid is : %d", getpid());
        exit(0);
    }else if(pid > 0){
        printf("\n Hello I am parent process ");
        printf("\n My actual pid is : %d \n ", getpid());
        wait(NULL);
        exit(1);
    }
}