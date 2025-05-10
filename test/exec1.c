#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

    printf("PID of exec1: %d\n", getpid());
    char  * args[] = {"Hello", "Neso", "Academy", NULL};
    execv("./exec2", args); 
    printf("Back to ex1.c");
    return 0;
}