#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

void main() {
    int fd[2];
    // Si no pongo esto me lee caracteres especiales
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid2;
    char buffer[30];

    // p1
    pid2 = fork();


    if (pid2 == 0) { // Proceso hijo
        close(fd[1]); // close escritura
	// El de lectura se queda a la espera del la escritura
        printf("Soy el proceso hijo con pid %d\n", getpid());
        read(fd[0], buffer, 20);
        printf("Fecha/hora: %s", buffer);

        close(fd[0]); // close lectura

    } else { // Proceso padre
        close(fd[0]); // close lectura
        time_t curtime;

        time(&curtime);

        write(fd[1], ctime(&curtime), 20);
        close(fd[1]); // close escritura
    }
}

