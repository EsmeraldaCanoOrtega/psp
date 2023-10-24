/*  El/los proceso/s padre/s deberá/n esperar a que sus hijo/s termine/n
    El proceso P1 define una variable acumulado igual al número de su pid
    Cada proceso hijo mostrará por pantalla el valor de dicha variable 
    incrementado en 10 si su pid es par o decrementado en 100 si es impar.
*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void parOImpar(int procesoN, int acumulado) {
    if(getpid()%2 == 0){
        printf("P%d de PID: %d\n",procesoN,(acumulado + 10));
    }else{
        printf("P%d de PID: %d\n",procesoN,(acumulado - 100) );
    }
}
void main(){

    pid_t p1, p2, p2h, p3h, p3;
    
    int acumulado, procesoN = 1;
    
    acumulado = getpid();
    
    p2 = fork();
    // Código p1 y p2
    if(p2 == 0){
        procesoN += 1;
        // p2
        p3 = fork();
        // p2 y p3
        if(p3 == 0){
            //p3
            procesoN += 1;
            parOImpar(procesoN, acumulado);
        
        }else{
            //p2 y p3
            wait(NULL);
            //p2
            parOImpar(procesoN, acumulado);
        }
    }else{
    	wait(NULL);
        //p1
        p2h = fork();
        // p1 y p2h
        if(p2h == 0){
            procesoN += 1;
            //p2h
            p3h = fork();
            // p2h y p3h
            if(p3h == 0){
                //p3h
                 procesoN += 1;
                parOImpar(procesoN, acumulado);
            }else{
                wait(NULL);
                parOImpar(procesoN, acumulado);              
            }
        }else{
            wait(NULL);
            parOImpar(procesoN, acumulado);
        }
    }
}