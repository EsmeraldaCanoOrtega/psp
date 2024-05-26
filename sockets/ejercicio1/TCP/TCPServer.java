import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class TCPServer {
    public static void main(String[] args) throws IOException {
		//crea el server en el puerto
        int puerto = 1251;
        ServerSocket servidor = new ServerSocket(puerto);

        Socket cliente1;
        System.out.println("Estamos esperando el numero del cliente 1 ");
        cliente1 = servidor.accept();

		// Se crea una bandeja de entrada del cliente1
        InputStream entrada;
        entrada = cliente1.getInputStream();
        DataInputStream flujoEntrada = new DataInputStream(entrada);

		// espera hasta que lea dato
        int num = flujoEntrada.readInt();
        System.out.println("Num: " + num);

        Socket cliente2 ;
        System.out.println("Estamos a que se cree el cliente 2 ");
        cliente2 = servidor.accept();

		// Se crea una bandeja de salida y manda num para cliente2
        DataOutputStream flujoSalida = new DataOutputStream(cliente2.getOutputStream());
        flujoSalida.writeInt(num);

        // Se crea una bandeja de entrada y recibe num de cliente2
        int facto;
        DataInputStream flujoEntrada2 = new DataInputStream(cliente2.getInputStream());
        facto = flujoEntrada2.readInt();

        // Se crea una bandeja de salida y manda num para cliente1
        System.out.println("FActo: " + facto);
        DataOutputStream flujoSalida2 = new DataOutputStream(cliente1.getOutputStream());
        flujoSalida2.writeInt(facto);

        cliente1.close();
        cliente2.close();

    }
}