#include <stdio.h>
#include <unistd.h>

int main(){
    printf("El pid del proceso padre es: %d\n",getppid()); //getppid obtiene el ID del proceso padre del proceso actual.
    return 0;
}