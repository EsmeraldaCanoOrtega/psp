#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
    pid_t pid1, pid2;
    printf("AAA \n");

    pid1 = fork();
    if (pid1 == 0)
    {
        printf("BBB \n");
    }
    else
    {
        wait(NULL);
        pid2 = fork(); // EL PROCESO PRINCIPAL TENDRIA DOS PROCESOS HIJOS
        wait(NULL);// AQUI ESPERARIA A QUE SU HIJO QUE ACABA DE CREARSE EJECUTARA TODO EL BLOQUE DE CODIGO Y EL PADRE EJECUTARIA
        printf("CCC \n");
        
    }
    exit(0);
}