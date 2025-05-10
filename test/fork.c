#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    fork();   // number of process = 2^n where n is the nubmer of fork
    fork();
    fork();
    printf("Hello process id = %d \n", getpid());
    return 0;
}