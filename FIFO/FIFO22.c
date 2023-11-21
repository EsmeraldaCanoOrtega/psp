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
    const char *pipe_path = "PIPE02";

    int fd_pipe = open(pipe_path, O_RDONLY); // Abrir PIPE02 para leer

    // Leer el número del PIPE02
    int number;
    read(fd_pipe, &number, sizeof(number));

    // Calcular el factorial del número
    int result = factorial(number);

    // Cerrar PIPE02
    close(fd_pipe);

    // Abrir PIPE02 para escribir el resultado
    fd_pipe = open(pipe_path, O_WRONLY);

    // Escribir el resultado en PIPE02
    write(fd_pipe, &result, sizeof(result));

    // Cerrar PIPE02
    close(fd_pipe);

    return 0;
}
