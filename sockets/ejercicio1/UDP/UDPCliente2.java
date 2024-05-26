import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDPCliente2 {
    public static void main(String[] args) throws IOException {
        DatagramSocket socket = new DatagramSocket(12346);
        // se queda a la espera del paquete envuelto
        byte[] receiveData = new byte[1024];
        DatagramPacket recibePack1 = new DatagramPacket(receiveData, receiveData.length);
        socket.receive(recibePack1);
        // desenvuelve mi paquete y calcula
        String num = new String(recibePack1.getData(), 0, recibePack1.getLength());
        int number = Integer.parseInt(num);
        int factorial = calculateFactorial(number);

        // se ha quedao con la ip del primer paquete
        InetAddress address = recibePack1.getAddress();
        int port = recibePack1.getPort();

        // manda el paquete con el factorial
        byte[] sendData = String.valueOf(factorial).getBytes();
        DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, address, port);
        socket.send(sendPacket);

        socket.close();
    }

    private static int calculateFactorial(int n) {
        if (n <= 1)
            return 1;
        else
            return n * calculateFactorial(n - 1);
    }
}
