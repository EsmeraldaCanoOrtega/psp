#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h> 

bool printPID(pid_t pidOrigen, int numeroProceso) {
    bool abuelo = false;
    printf("PID de P%d: %d\n", numeroProceso, getpid());
    if (pidOrigen <= getpid() - 2) {  
        printf("Tiene abuelo y su abuelo es:"); 
        abuelo = true;
    }
    return abuelo;
}

void main() {  

    pid_t pid1, pid2, pid3, pid4, pid3H, pid4H;
    int procesoN = 1, abuelo1, abuelo2;
    abuelo1 = getpid();

    pid2 = fork();
    // Código p1 y p2
    if (pid2 == 0) {
    	abuelo2 = getpid();
        // Código p2
        procesoN += 1;
        // Creo p3
        pid3 = fork();
        // Código p2 y p3
        if (pid3 == 0) {
            // Código p3
            procesoN += 1;
            // Creo p4
            pid4 = fork();
            // Código p3 y p4
            if (pid4 == 0) {
                // Código p4
                procesoN += 1;
                printf("%d \n", printPID(abuelo2, procesoN) ? abuelo2 : 0);  
            } else {
                wait(NULL);
                // Código p3
                printf("%d \n", printPID(abuelo1, procesoN) ? abuelo1 : 0);  
            }
        } else {
            wait(NULL);
            // Código p2
            // Creo p3 hermano menor
            pid3H = fork();
            // Código p2 y p3h
            if (pid3H == 0) {  
                // Código p3h
                procesoN += 1;
                // Creo p4h
                pid4H = fork();
                // Código p3h y p4h
                if (pid4H == 0) {
                    // Código p4h
                    procesoN += 1;
                    printf("%d \n", (printPID(abuelo2, procesoN)) ? abuelo2 : 0);  
                } else {
                    wait(NULL);
                    // Código p3h
                    printf("%d \n", (printPID(abuelo1, procesoN)) ? abuelo1 : 0);  
                }
            } else {
                wait(NULL);
                wait(NULL);
                printf("%d \n", printPID(abuelo1, procesoN) ? abuelo1 : 0); 
            }
        }
    } else {
        wait(NULL);
        // Código p1
        printf("%d \n", printPID(abuelo1, procesoN) ? abuelo1 : 0);  
    }
}