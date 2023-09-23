/* Mostrar el PID y el PPID de un proceso */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*gcc ps1.c -o ps1 --> ponerlo en la terminal para tener un ejecutable*/

void main() {
    /* Zona de declaración de variables (siempre al principio) */
    pid_t pid_proceso, pid_proceso_padre;

    /* Función getpid -> devuelve el PID del proceso en ejecución */
    pid_proceso = getpid();
    /* Función getppid -> devuelve el PPID del proceso en ejecución */
    pid_proceso_padre = getppid();

    printf("PID de proceso actual es: %d\n", pid_proceso);
    printf("PID de proceso padre es: %d\n", pid_proceso_padre);
}