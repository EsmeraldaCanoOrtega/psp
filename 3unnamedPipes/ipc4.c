#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

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

        srand(time(NULL));
        int num = rand() % 11; // Generar un número aleatorio entre 0 y 10
        printf("El proceso padre genera el número %d en el pipe1\n", num);
        write(pipe1[1], &num, sizeof(int));
        close(pipe1[1]);

        int factorial_result;
        read(pipe2[0], &factorial_result, sizeof(int));
        close(pipe2[0]);

        printf("El factorial calculado por el proceso hijo: %d! = %d\n", num, factorial_result);
    } else {
        // Proceso hijo
        close(pipe1[1]); // Cerrar escritura de pipe1
        close(pipe2[0]); // Cerrar lectura de pipe2

        int num;
        read(pipe1[0], &num, sizeof(int));
        close(pipe1[0]);

        int factorial = 1;
        for (int i = 1; i <= num; i++) {
            factorial *= i;
        }

        write(pipe2[1], &factorial, sizeof(int));
        close(pipe2[1]);
    }
}
