#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

void main() {
    int fd[2];
    if (pipe(fd) == -1) {
        fprintf(stderr, "Error al crear el pipe\n");
        exit(1);
    }

    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Error al crear el proceso hijo\n");
        exit(1);
    }

    if (pid > 0) {
        //OJOOOOOOOOO
        //EL PADRE DEBE SER LECTURA O SI NO ME PONE NUMEROS FUERA DE RANGO
        // Proceso padre
        close(fd[1]); // Cerrar escritura

        int num1, num2;
        read(fd[0], &num1, sizeof(int));
        read(fd[0], &num2, sizeof(int));

        printf("%d + %d = %d\n", num1, num2, num1 + num2);
        printf("%d - %d = %d\n", num1, num2, num1 - num2);
        printf("%d * %d = %d\n", num1, num2, num1 * num2);
        printf("%d / %d = %d\n", num1, num2, num1 / num2);

        close(fd[0]); // Cerrar lectura
    } else {
        // Proceso hijo
        close(fd[0]); // Cerrar lectura
        // sino se pone time(NULL) la secuencia de números generada por rand 
        //sería la misma en cada ejecución del programa
        srand(time(NULL));
        int num1 = rand() % 50 + 1;
        int num2 = rand() % 50 + 1;

        write(fd[1], &num1, sizeof(int));
        write(fd[1], &num2, sizeof(int));

        close(fd[1]); // Cerrar escritura
    }
}





