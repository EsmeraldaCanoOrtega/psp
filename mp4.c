//1.- Dibuja un gráfico de la jerarquía de procesos que genera la ejecución de este código,
//suponiendo que el pid del programa mp4 es el 1000 y los pids se generan de uno en uno en orden creciente

// 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main()
{
 printf("CCC \n");
 if (fork()!=0)
 {
 printf("AAA \n");
 } else printf("BBB \n");
 exit(0);
}
