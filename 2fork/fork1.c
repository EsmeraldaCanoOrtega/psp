/* ¿Cuál será el orden de ejecución de los procesos?¿Será siempre el mismo? Justifica la respuesta
-   En este caso, que he puesto wait, para que ningun proceso se quede huerfano
-   pero aun asi, hay posibilidades que el proceso p3 que se ejecute antes p2, es decir nunca será el mismo proceso*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void printPID(pid_t pid) {
    if (pid % 2 == 0) {
        printf("Soy el proceso con PID %d y mi padre es %d\n", getpid(), getppid());
    } else {
        printf("Soy el proceso con PID %d\n", getpid());
    }
}
void main() {
    pid_t pid_p2, pid_p3, pid_p4;

    // Creo p2
    pid_p2 = fork();

    if (pid_p2 == -1) {
        printf("ERROR !!! No se ha podido crear el proceso hijo...");
        exit(-1);
    } else if (pid_p2 == 0) {
        // Código p2
        printPID(getpid());
    } else {
        // Código p1
        // Creo p3
        pid_p3 = fork();
        // Código p1 y p3
        if (pid_p3 == -1) {
            printf("ERROR !!! No se ha podido crear el proceso hijo...");
            exit(-1);
        } else if (pid_p3 == 0) {
            // Código p3
            printPID(getpid());

            // Creo p4
            pid_p4 = fork();
            // Código p3 y p4
            if (pid_p4 == -1) {
                printf("ERROR !!! No se ha podido crear el proceso hijo...");
                exit(-1);
            } else if (pid_p4 == 0) {
                // Código p4
                printPID(getpid());
            }else{
            	// Código p3
            	wait(NULL);
            	printf("Procesos p4 completado\n");
            }
        } else {
            // Código p1
            wait(NULL);
            wait(NULL);
            printPID(getpid());
            printf("Procesos hijos p2 y p3 completados\n");
        }
    }
}

