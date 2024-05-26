#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid;
  
  pid = fork();

  if (pid == -1 ) {
    printf("ERROR !!! No se ha podido crear el proceso hijo...");
    exit(-1);
  }else{
    if(pid == 0){
      pid_t pid_hijo;
    
      pid_hijo = fork();
      
      if(pid_hijo ==-1){
        printf("ERROR !!! No se ha podido crear el proceso nieto...");
      }else{
        if(pid_hijo ==0){
        //pid (SU ID) = 3735 ppid (id Padre) = 3734
        printf("Soy el proceso NIETO ... pid = %d y el pid de mi padre = %d \n",getpid(),getppid());  
        printf("**************************************** \n");	
        }else{
        //pid (SU ID) = 3734 ppid (id Padre) = 3733
        wait(NULL);
        printf("Soy el proceso PADRE ... pid = %d y el pid de mi padre = %d \n",getpid(),getppid());  
        printf("**************************************** \n");	
      }
      }
    }else {
        //ABUELO = 3734
        //pid (SU ID) = 3733 ppid (id Padre) = 2960
        wait(NULL); 
        printf("Soy el proceso Abuelo ... pid = %d y el pid de mi hijo = %d \n",getpid(),pid);	 
  }
  }
  exit(0);
}