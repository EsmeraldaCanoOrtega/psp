//El proceso padre deberá crear un proceso hijo que mostrará el nombre del alumno.
//El proceso padre deberá esperar a que su hijo termine,
// y mostrará por pantalla el pid del hijo y el suyo propio
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid, pid_hijo, waitHijo;
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
        printf("Soy el proceso HIJO ... mi nombre es Esmeralda Caño \n");
        printf("Pid del proceso Hijo ... pid = %d \n",getpid());
        pid_hijo = getpid();

    }else {
        waitHijo = wait(NULL); //espera la finalización del proceso hijo
        printf("Pid del proceso Padre ... pid = %d y el pid de su hijo = %d \n",getpid(),var);	
  }
  }
  //Tanto el proceso padre y el proceso hijo llegan a la salida
  exit(0);
}