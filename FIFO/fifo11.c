#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    const char *fifo1_path = "FIFO1";
    const char *fifo2_path = "FIFO2";

    mkfifo(fifo1_path, 0666); // Crear FIFO1
    mkfifo(fifo2_path, 0666); // Crear FIFO2

    int fd_fifo1 = open(fifo1_path, O_WRONLY); // Abrir FIFO1 para escribir

    // Generar un número aleatorio entre 0 y 10
    srand(time(NULL));
    int random_number = rand() % 11;

    // Escribir el número en FIFO1
    write(fd_fifo1, &random_number, sizeof(random_number));

    // Cerrar FIFO1
    close(fd_fifo1);

    // Esperar un momento para que fifo12 tenga la oportunidad de abrir FIFO2
    sleep(1);

    // Abrir FIFO2 para leer el resultado
    int fd_fifo2 = open(fifo2_path, O_RDONLY);

    // Leer el resultado del cálculo
    int result;
    read(fd_fifo2, &result, sizeof(result));

    // Mostrar el resultado
    printf("Resultado del factorial (fifo11): %d\n", result);

    // Cerrar FIFO2 y eliminar los FIFOs
    close(fd_fifo2);
    unlink(fifo1_path);
    unlink(fifo2_path);

    return 0;
}
