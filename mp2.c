#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid, pid_hijo,pid_nieto;
  pid_t PEPE;
  pid_t nieto;
  
  PEPE = fork();
  // Se CREA un proceso hijo, la función fork() devuelve:
  // -1 -> se produce cualquier error
  //  0 -> si estamos en el proceso hijo
  // +1 -> si estamos en el proceso padre

  if (PEPE == -1 ) {
    printf("ERROR !!! No se ha podido crear el proceso hijo...");
    exit(-1);
  }else{
    if(PEPE == 0){
    
      nieto = fork();
      
      if(nieto ==-1){
        printf("ERROR !!! No se ha podido crear el proceso nieto...");
      }else{
        if(nieto ==0){
        //pid (SU ID) = 3735 ppid (id Padre) = 3734
        printf("Soy el proceso NIETO ... pid = %d y el pid de mi padre = %d \n",getpid(),getppid());  
        printf("**************************************** \n");	
        }else{
        //pid (SU ID) = 3734 ppid (id Padre) = 3733
        pid_nieto = wait(NULL);
        printf("Soy el proceso PADRE ... pid = %d y el pid de mi padre = %d \n",getpid(),getppid());  
        printf("**************************************** \n");	
      }
      }
      
    }else {
        //ABUELO = 3734
        //pid (SU ID) = 3733 ppid (id Padre) = 2960
        pid_hijo = wait(NULL); //espera la finalización del proceso hijo
        printf("Soy el proceso Abuelo ... pid = %d y el pid de mi hijo = %d \n",getpid(),PEPE);	 
  }
  }
  //Tanto el proceso abuelo, padre y el proceso hijo llegan a la salida
  exit(0);
}