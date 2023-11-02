/*
Dos procesos que se comunican mediante un pipe
El proceso padre deberá escribir varios números en el pipe, 
para finalizar introducirá el carácter +
El proceso hijo mostrará por pantalla cada uno de los números recibidos y 
la suma de los mismos una vez recibido el carácter +*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void main() {
    // Crear un pipe. fd[0] para lectura y fd[1] para escritura
    int fd[2];
    char input[10];
    
    if (pipe(fd) == -1) {
        fprintf(stderr, "Error al crear el pipe\n");
        exit(1);
    }

    pid_t pid = fork();
    // Verificar errores en la creación del proceso hijo
    if (pid < 0) {
        fprintf(stderr, "Error al crear el proceso hijo\n");
        exit(1);
    }

    if (pid > 0) {
        // Proceso padre
        close(fd[0]); // Cerrar lectura

        printf("Escriba números para sumar. Para finalizar, ingrese el carácter '+'\n");
        // Bucle para la entrada de datos
        while (1) {
            printf("Numero a sumar: ");
            fgets(input, 10, stdin);
            // Verificar si se debe finalizar la entrada de datos
            if (strcmp(input, "+\n") == 0) {
                write(fd[1], input, strlen(input) + 1);
                break;
            }
            write(fd[1], input, strlen(input) + 1);
        }

        close(fd[1]); // Cerrar escritura
    } else {
        // Proceso hijo
        close(fd[1]); // Cerrar escritura

        int suma = 0;
        /*read() devuelve el número de bytes leídos desde el descriptor de archivo especificado. 
        Si no hay más datos que leer devolverá 0. 
        Si ocurre un error durante la lectura, la función read() devolverá -1.
        */while (read(fd[0], input, sizeof(input)) > 0) {
            /*strcmp devolverá 0 si las cadenas a comparar son iguales. En caso de que la primera sea “menor”
que la segunda, devolverá un número negativo, y finalmente si la primera es “mayor” que la
segunda, devolverá un número positivo*/ 
            if (strcmp(input, "+\n") == 0) {
                printf("Recibido carácter +\n");
                printf("La suma total es igual a: %d\n", suma);
                break;
            }
            suma += atoi(input); //atoi convierte una cadena de caracteres a entero
        }

        close(fd[0]); // Cerrar lectura
    }
}

