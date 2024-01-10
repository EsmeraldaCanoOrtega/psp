public class EjecHilos {
    public static void main(String[] args) {
        Thread hiloPar = new Thread(new HiloParImparR(2));
        Thread hiloImpar = new Thread(new HiloParImparR(1));
        hiloImpar.setPriority(10);
        hiloPar.start();
        hiloImpar.start();
    }
}
