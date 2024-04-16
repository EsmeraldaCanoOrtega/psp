// El proceso P1 es padre de P2 y de P3
// El proceso P2 deberá dormir 10 segundos y mostrar el mensaje “Despierto” al finalizar
// El proceso P3 deberá mostrar por pantalla su pid y el de su padre, indicando que es el proceso P3
// El/los proceso/s padre/s deberá/n esperar a que sus hijo/s termine/n
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
    pid_t var;

    var = fork();

    if (var == -1)
    {
        printf("ERROR !!! No se ha podido crear el proceso hijo...");
        exit(-1);
    }
    else if (var == 0)
    {

        sleep(10);
        printf("Soy el proceso Hijo mayor ... pid = %d y el pid de mi padre = %d \n", getpid(), getppid());
    }
    else
    {
        pid_t var2;
        var2 = fork();
        if (var2 == -1)
        {
            printf("ERROR !!! No se ha podido crear el proceso hijo...");
            exit(-1);
        }
        else if (var2 == 0)
        {
            printf("Soy el proceso Hijo menor ... pid = %d y el pid de mi padre = %d \n", getpid(), getppid());
        }
        else
        {
            wait(NULL);
            wait(NULL);
            printf("Soy el proceso Padre ... pid = %d y el pid de mi hijo mayor = %d y el pid de mi hijo menor = %d \n", getpid(), var, var2);
        }
    }
    exit(0);
}