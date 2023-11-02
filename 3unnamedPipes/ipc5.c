#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void main() {
    int pipe1[2], pipe2[2];
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        fprintf(stderr, "Error al crear los pipes\n");
        exit(1);
    }

    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Error al crear el proceso hijo\n");
        exit(1);
    }

    if (pid > 0) {
        // Proceso padre
        close(pipe1[0]); // Cerrar lectura de pipe1
        close(pipe2[1]); // Cerrar escritura de pipe2

        char dni[9];
        printf("Introduce el número de tu DNI: ");
        fgets(dni, 9, stdin);
        write(pipe1[1], dni, strlen(dni) + 1);
        close(pipe1[1]);

        char letra;
        read(pipe2[0], &letra, sizeof(char));
        close(pipe2[0]);

        printf("La letra del NIF es %c\n", letra);
    } else {
        // Proceso hijo
        close(pipe1[1]); // Cerrar escritura de pipe1
        close(pipe2[0]); // Cerrar lectura de pipe2

        char dni[9];
        read(pipe1[0], dni, 9);
        close(pipe1[0]);

        // Cálculo de la letra del NIF
        const char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
        int dni_number = atoi(dni);
        char letra = letras[dni_number % 23];

        write(pipe2[1], &letra, sizeof(char));
        close(pipe2[1]);

        printf("HIJO la letra calculada: %c\n", letra);
    }
}
