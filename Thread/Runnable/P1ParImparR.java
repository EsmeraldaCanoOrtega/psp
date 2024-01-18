class HiloR implements Runnable {
    private int tipo;

    public HiloR(int tipo) {

        this.tipo = tipo;
    }

    @Override
    public void run() {
        if (tipo == 1) {

            Thread.currentThread().setName("xx");
            for (int i = 2; i <= 100; i += 2) {

                System.out.println("HILO " + Thread.currentThread().getName() + " generando número par " + i);
            }
        } else if (tipo == 2) {
            //Thread.currentThread().setPriority(Thread.MAX_PRIORITY);
            Thread.currentThread().setName("yy");
            for (int i = 101; i <= 200; i += 2) {
                System.out.println("HILO " + Thread.currentThread().getName() + " generando número impar " + i);
            }
        }
    }
}
public class P1ParImparR {
    public static void main(String[] args) {
        HiloR	hiloPar = new HiloR(2);
        HiloR	hiloImpar = new HiloR(1);
        
        new Thread(hiloImpar).setPriority(10);

        new Thread(hiloPar).start();
        new Thread(hiloImpar).start();
    }
}


