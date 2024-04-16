//Que salida genera este código? ¿Podria producirse otra salida? Justifica la respuesta
// En caso de no poner un wait, no se puede determinar que proceso se ejecutaria primero


// 3.-Modificar el código para que la salida por pantalla sea:
// CCC
// BBB
// AAA
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
    pid_t pid;
    printf("CCC \n");
    if (fork() != 0)
    {
        // 1.- pid 1000
        wait(NULL);
        printf("AAA \n");
    }
    else
    {
        // 1.- pid 1001
        printf("BBB \n");
    }
    exit(0);
}