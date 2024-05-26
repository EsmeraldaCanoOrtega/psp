
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

public class TCPCliente2 {
    public static void main(String[] args) throws IOException {
        String ip = "localhost";//192.168.204.49
        int puerto = 1251;
        // Creación Socket Cliente
        Socket Cliente = new Socket(ip, puerto);
        System.out.println("El cliente 2 ha sido creado ");

        /** Se crea una bandeja de entrada y recibe num de server*/
        DataInputStream flujoEntrada = new DataInputStream(Cliente.getInputStream());
        int num = flujoEntrada.readInt();
        System.out.println("Número: " + num);

        int facto = 1;
        for (int i = 1; i <= num; i++) {
            facto = facto * i;
        }

        System.out.println("Factorial: " + facto);
        // Se crea una bandeja de salida y manda num para server
        DataOutputStream flujoSalida = new DataOutputStream(Cliente.getOutputStream());
        flujoSalida.writeInt(facto);
    }
}
