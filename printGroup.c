#include <stdio.h>
#include <unistd.h>

int main() {
    printf("El pid del grupo es: %d\n", getpgrp()); //getpgrp obtiene el ID del grupo de procesos al que pertenece el proceso actual.
    return 0;
}