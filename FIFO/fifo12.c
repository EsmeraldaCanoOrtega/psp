#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    const char *fifo1_path = "FIFO1";
    const char *fifo2_path = "FIFO2";

    int fd_fifo1 = open(fifo1_path, O_RDONLY); // Abrir FIFO1 para leer

    // Leer el número del FIFO1
    int number;
    read(fd_fifo1, &number, sizeof(number));

    // Calcular el factorial del número
    int result = factorial(number);

    // Cerrar FIFO1
    close(fd_fifo1);

    // Abrir FIFO2 para escribir el resultado
    int fd_fifo2 = open(fifo2_path, O_WRONLY);

    // Escribir el resultado en FIFO2
    write(fd_fifo2, &result, sizeof(result));

    // Cerrar FIFO2
    close(fd_fifo2);

    return 0;
}
