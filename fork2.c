//  same program, different code.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pid;
    pid = fork();
    if(pid < 0){
        printf("\n Error ");
        exit(1);
    }else if(pid == 0 ){
        printf("\nHello i am child process");
        printf("\nMy pid is : %d ",getpid());
        exit(0);
    }else{
        printf("\nHello I am parent process");
        printf("\nMy actual pid is : %d", getpid());
        exit(1);
    }
}