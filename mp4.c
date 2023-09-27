//1.- Dibuja un gráfico de la jerarquía de procesos que genera la ejecución de este código,
//suponiendo que el pid del programa mp4 es el 1000 y los pids se generan de uno en uno en orden creciente

//2.-¿Qué salida genera este código? ¿Podría producirse otra salida? Justifica la respuesta
// CCC,AAA,BBB. Podría darse la situacion que el proceso BBB se ejecutará antes
//ya que no hay un wait que controle los procesos

//3.-Modificar el código para que la salida por pantalla sea:
 //CCC
 //BBB
 //AAA
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main(){
    pid_t pid;
 printf("CCC \n");
 if (fork()!=0){
    // 1.- pid 1000
    pid = wait(NULL);
 printf("AAA \n");
 } else{
    // 1.- pid 1001
    printf("BBB \n");
 } 
 exit(0);
}