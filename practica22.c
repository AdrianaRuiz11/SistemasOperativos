#include <stdio.h> //se utiliza para el printf y fgets
#include <stdlib.h> //administra la memoria dinamica y otros aspectos del sistema, como exit para salir del prog. por si hay algun error
#include <unistd.h> //se utiliza para el fork y execvp
#include <sys/wait.h> //wait
#include <string.h> //strcmp y strtok

#define MAX_CMD_LEN 100 // Longitud máxima del comando
#define MAX_ARGS 10 // Máximo número de argumentos en el comando

int main() {
    char comando[MAX_CMD_LEN]; // Almacenará el comando ingresado por el usuario
    char *args[MAX_ARGS + 1]; // Almacenará los argumentos del comando

    while (1) {
        // Imprime el prompt y lee el comando ingresado por el usuario
        printf("$ ");
        fflush(stdout);  //limpia el buffer de salida.
        fgets(comando, MAX_CMD_LEN, stdin); //fgets su estructura es el nombre de la variable, tamanio, biblioteca)

        // Elimina el salto de línea al final del comando. 
        comando[strlen(comando)-1] = '\0'; //strlen se utiliza para obtener la longitud actual de la cadena comando
                                           //y luego se resta uno para obtener la posicion del ultimo caracter de la cadena.


        //strcmp compara dos cadenas de caracteres y devuelve 0 si las cadenas son iguales.
        if (strcmp(comando, "exit") == 0) { // Si el usuario ingresó "exit", terminamos el programa
            printf("Saliendo del programa...\n");
            break;
        }

        // Divide el comando en sus diferentes argumentos
        char *token = strtok(comando, " "); //strktok tiene dos argumentos: la variable comando se va a dividir en tokens y 
                                            //su delimitador para dividir la cadena sera con los espacios.
        int arg_index = 0;

        while (token != NULL) { //Recorre la cadena de caracteres restantes.
                                //Parara hasta que ya no hayan mas tokens o se haya alcanzado el num. maximo de argumentos.
            
            // Almacena el argumento en el array de argumentos.
            //EL primer valor del token se almacenara en el arreglo args.
            args[arg_index] = token;
            arg_index++;

            // Si llegamos al máximo número de argumentos, salimos del ciclo
            if (arg_index >= MAX_ARGS) {
                break;
            }

            // Avanza al siguiente token.
            //Se ocupa el NULL para indicar que se desea continuar desde donde se quedo la ultima llamada.
            token = strtok(NULL, " ");
        }

        // Agrega un puntero nulo al final del array de argumentos.
        //Es necesario el NULL para indicar que no hay mas argumentos.
        args[arg_index] = NULL;

        // Crea un proceso hijo para ejecutar el comando
        pid_t pid = fork();

        if (pid < 0) { // Error al crear el proceso hijo
            //Se utiliza fprintf porque escribe los datos en un archivo.
            //stderr se utiliza para imprimir mensajes de error.
            fprintf(stderr, "Error al crear el proceso hijo\n");
            exit(1);
        }
        else if (pid == 0) { // Proceso hijo
            // Ejecuta el comando con los argumentos ingresados
            execvp(args[0], args);

            // Si llegamos aquí, hubo un error en execvp
            fprintf(stderr, "Error al ejecutar el comando\n");
            exit(1);
        }
        else { // Proceso padre
            // Espera a que termine el proceso hijo
            waitpid(pid,NULL,0);
        }
    }

    return 0;
}