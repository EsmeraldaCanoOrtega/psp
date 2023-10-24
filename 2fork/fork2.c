#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void printPID(pid_t pid,int numeroProceso) {
    printf("PID de P%d: %d\n", numeroProceso, getpid());
    printf("PPID de P%d: %d\n", numeroProceso, getppid());
    printf("Suma = %d\n", getpid() + getppid());
    printf("--------------------------------\n");
}
void main(){

    pid_t pid2, pid3, pid4;
    int procesoN = 1;

    pid2 = fork();
    // Código p1 y p2
    if (pid2 == -1){
        printf("ERROR !!! No se ha podido crear el proceso hijo...");
        exit(-1);
    }else if (pid2 == 0){
        // Código p2
        procesoN += 1;
        // Creo p3
        pid3 = fork();
        // Código p2 y p3
        if (pid3 == -1){
            printf("ERROR !!! No se ha podido crear el proceso hijo...");
            exit(-1);
        }else if (pid3 == 0){
            // Código p3
            procesoN += 1;
            // Creo p4
            pid4 = fork();
            // Código p3 y p4
            if (pid4 == -1){
                printf("ERROR !!! No se ha podido crear el proceso hijo...");
                exit(-1);
            }else if (pid4 == 0){
                // Código p4
                procesoN += 1;
                printPID(getpid(),procesoN);
            }else{
            
                wait(NULL);
                // Código p3
                printPID(getpid(),procesoN);
            }
        }else{
            wait(NULL);
            // Código p2
            //OJO si no pongo nada pone p1 de sumar
            printPID(getpid(),procesoN);
        }
    }else{
        wait(NULL);
        // Código p1
        printPID(getpid(),procesoN);
    }
}