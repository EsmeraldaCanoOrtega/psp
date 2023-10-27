/*
Dos procesos que se comunican mediante un pipe
El proceso padre deberá escribir varios números en el pipe, 
para finalizar introducirá el carácter +
El proceso hijo mostrará por pantalla cada uno de los números recibidos y 
la suma de los mismos una vez recibido el carácter +*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>

void main() {
    int fd[2];
    char buffer[30];
    pid_t pid;
    
    // p1
    pid = fork();
    // p1 y p2
    if (pid == 0) {
        int sum = 0;
        close(fd[1]); // close escritura
        while (true) {
            read(fd[0], buffer, sizeof(buffer));
            if (buffer[0] == '+') {
                printf("Recibido carácter +\n");
                printf("La suma total es igual a: %d\n", sum);
                break;
            } 
            // sprintf() convierte un entero en una cadena de caracteres
            // función convierte una cadena de caracteres a entero
            int num = atoi(buffer);
            sum += num;
        }
    } else {
        close(fd[0]); // close lectura
        
        while (true) {
            printf("Numero a sumar:");
            //char* aqui le pasamos un String
            //fgets(char* string, int length, FILE * stream);
            fgets(buffer, sizeof(buffer), stdin);
            //stdin for reading from the standard input.
            write(fd[1], buffer, strlen(buffer));
            // strlen() funcion que le pasas por parametro un String returns su length
            if (buffer[0] == '+') {
                break;
            }
        }
        wait(NULL); // Espera a que el hijo termine
    }
}
