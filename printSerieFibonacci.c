#include <stdio.h>

int fibonacci(int n);

int main() {
    int n, i;
    
    printf("Ingrese la cantidad de términos que desea mostrar en la serie de Fibonacci: ");
    scanf("%d", &n);
    
    printf("Serie de Fibonacci:\n");
    
    for (i = 0; i < n; ++i) {
        printf("%d, ", fibonacci(i));
    }
    
    return 0;
}

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
