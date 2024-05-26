/**
 * Implementar dos procesos java que se comunicarán entre sí utilizando objetos sobre
 * socets TCP. Uno de los procesos realizara la funcion de servidor, mientras que el otro
 * actuara como cliente
 * Proceso servidor SocketServerBolsa
 * tiene implementado el esquelet
 *
 * Cliente Codigo accion bursatil: REPS
 * ¿Que inforion desea conocer ()?*/
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

public class TCPCliente1 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        String ip = "localhost"; //192.168.204.49
        int puerto = 1251;

        Socket cliente = new Socket(ip, puerto);
        System.out.println("El cliente 1 ha sido creado ");

        System.out.println("Introduce el número que quieres pasar al servidor: ");
        int num = sc.nextInt();

        /** Se crea una bandeja de salida y manda num para server*/
        DataOutputStream flujoSalida = new DataOutputStream(cliente.getOutputStream());
        flujoSalida.writeInt(num);

        /** Se crea una bandeja de entrada y recibe num de server*/
        DataInputStream flujoEntrada = new DataInputStream(cliente.getInputStream());
        int facto = flujoEntrada.readInt();

        System.out.println("El factorial es: " + facto);

        cliente.close();
    }
}