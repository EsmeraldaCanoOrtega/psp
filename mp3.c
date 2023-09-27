// El proceso P1 es padre de P2 y de P3
// El proceso P2 deberá dormir 10 segundos y mostrar el mensaje “Despierto” al finalizar
// El proceso P3 deberá mostrar por pantalla su pid y el de su padre, indicando que es el proceso P3
// El/los proceso/s padre/s deberá/n esperar a que sus hijo/s termine/n
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid, pid_hijo,pid_hijo2;
  pid_t PEPE;
  pid_t hijo2;
  
  PEPE = fork();
  // Se CREA un proceso hijo, la función fork() devuelve:
  // -1 -> se produce cualquier error
  //  0 -> si estamos en el proceso hijo
  // +1 -> si estamos en el proceso padre
  if (PEPE == -1 ) {
    printf("ERROR !!! No se ha podido crear el proceso hijo...");
    exit(-1);
  }else if (PEPE == 0 ) {
    printf("Soy el proceso Hijo mayor ... pid = %d y el pid de mi padre = %d \n",getpid(),getppid());  
    sleep(10);
    printf("Despertandose hijo mayor\n");
    printf("**************************************** \n");
    }else{
        pid_hijo2 = fork();
        if (pid_hijo2 == -1 ) {
        printf("ERROR !!! No se ha podido crear el proceso hijo...");
        exit(-1);
        }
        else if(pid_hijo2 == 0){
        printf("Soy el proceso Hijo menor ... pid = %d y el pid de mi padre = %d \n",getpid(),getppid());  
        printf("**************************************** \n");	
        }else{
        hijo2 = wait(NULL);
        pid_hijo = wait(NULL); //espera la finalización del proceso hijo
        printf("Soy el proceso Padre ... pid = %d y el pid de mi hijo mayor = %d y el pid de mi hijo menor = %d \n",getpid(),PEPE,pid_hijo2);
        }    	 
  }
  exit(0);
  }
  
