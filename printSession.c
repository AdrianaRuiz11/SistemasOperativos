#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("Información de la sesión:\n");
    printf("ID de usuario: %d\n", getuid());
    printf("ID de grupo: %d\n", getgid());
    printf("ID de proceso: %d\n", getpid());
    printf("ID de proceso padre: %d\n", getppid());
    printf("ID de sesión: %d\n", getsid(0));
    return 0;
}