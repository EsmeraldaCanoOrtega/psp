#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid, pid_hijo;
  pid_t var;
  
  var = fork();
  // Se CREA un proceso hijo, la función fork() devuelve:
  // -1 -> se produce cualquier error
  //  0 -> si estamos en el proceso hijo
  // +1 -> si estamos en el proceso padre

  if (var == -1 ) {
    printf("ERROR !!! No se ha podido crear el proceso hijo...");
    exit(-1);
  }else{
    if(var == 0){
        //Pepe = 0
        //pid = 3070 ppid = 3069
        printf("Soy el proceso HIJO ... Variable Hijo = %d \n",var);
        printf("Soy el proceso HIJO ... pid = %d ppid= %d \n",getpid(),getppid());  

    }else {
        //Pepe = 3070
        //pid = 3069 ppid = 2960
        pid_hijo = wait(NULL); //espera la finalización del proceso hijo
        printf("Soy el proceso PADRE ... pid = %d ppid= %d \n",getpid(),getppid());	
        printf("Soy el proceso PADRE ... Variable var = %d \n",var);	 
  }
  }
  //Tanto el proceso padre y el proceso hijo llegan a la salida
  exit(0);
}