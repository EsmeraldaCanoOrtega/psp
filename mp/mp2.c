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
    else{
        if (var == 0){
            pid_t var2;

            var2 = fork();
            if (var2 == 0)
            {
                printf("Soy P3(Nieto): mi pid es %d y el de mi padre %d\n", getpid(), getppid());
            }
            else
            {
                wait(NULL);
                printf("Soy P2(Padre): mi pid es %d y el de mi padre %d\n", getpid(), getppid());
            }
        }
        else
        {
            wait(NULL);
            printf("Soy P1(Abuelo): mi pid es %d y el de mi hijo es %d \n", getpid(), var);
        }
    }
    exit(0);
}