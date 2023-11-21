#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    const char *pipe_path = "PIPE02";

    mkfifo(pipe_path, 0666); // Crear PIPE02

    int fd_pipe = open(pipe_path, O_WRONLY); // Abrir PIPE02 para escribir

    // Generar un número aleatorio entre 0 y 10
    srand(time(NULL));
    int random_number = rand() % 11;

    // Escribir el número en PIPE02
    write(fd_pipe, &random_number, sizeof(random_number));

    // Cerrar PIPE02
    close(fd_pipe);

    // Esperar un momento para que el otro extremo del tubo tenga la oportunidad de abrir PIPE02
    sleep(1);

    // Abrir PIPE02 para leer el resultado
    fd_pipe = open(pipe_path, O_RDONLY);

    // Leer el resultado del cálculo
    int result;
    read(fd_pipe, &result, sizeof(result));

    // Mostrar el resultado
    printf("Resultado del factorial: %d\n", result);

    // Cerrar PIPE02 y eliminar el tubo
    close(fd_pipe);
    unlink(pipe_path);

    return 0;
}
