/* ¿Cuál será el orden de ejecución de los procesos?¿Será siempre el mismo? Justifica la respuesta
-   En este caso, que he puesto wait, para que ningun proceso se quede huerfano
-   pero aun asi, hay posibilidades que el proceso p3 que se ejecute antes p2, es decir nunca será el mismo proceso*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void printPID(pid_t pid)
{
    if (pid % 2 == 0)
    {
        printf("Soy el proceso con PID %d y mi padre es %d\n", getpid(), getppid());
    }
    else
    {
        printf("Soy el proceso con PID %d\n", getpid());
    }
}
void main()
{
    pid_t pid, pid2, pid3;

    pid = fork();

    if (pid == -1)
    {
        printf("ERROR !!! No se ha podido crear el proceso hijo...");
        exit(-1);
    }
    else if (pid == 0)
    {
        printPID(getpid()); // p2
    }
    else
    {

        pid2 = fork();
        if (pid2 == 0)
        {

            pid3 = fork();
            // Código p3 y p4
            if (pid3 == -1)
            {
                printf("ERROR !!! No se ha podido crear el proceso hijo...");
                exit(-1);
            }
            else if (pid3 == 0)
            {
                // Código p4
                printPID(getpid());
            }
            else
            {
                wait(NULL);
                printPID(getpid());//p3
                printf("Procesos p4 completado\n");
            }
        }
        else
        {
            wait(NULL);
            wait(NULL);
            printPID(getpid());
            printf("Procesos hijos p2 y p3 completados\n");
        }
    }
}