#include <stdio.h>
#include <unistd.h>

int main(){

    printf("El ID del proceso actual es: %d\n", getpid());
    return 0;
}