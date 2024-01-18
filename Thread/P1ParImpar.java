class Hilo extends Thread {
    private int tipo;

    public Hilo(int tipo) {
        this.tipo = tipo;
    }

    @Override
    public void run() {
        if (tipo == 1) {
            this.setName("xx");
            for (int i = 2; i <= 100; i += 2) {
                System.out.println("HILO " + this.getName() + " generando número par " + i);
            }
        } else if (tipo == 2) {
            //this.setPriority(Thread.MAX_PRIORITY);
            this.setName("yy");
            for (int i = 101; i <= 200; i += 2) {
                System.out.println("HILO " + this.getName() + " generando número impar " + i);
            }
        }
    }
}

public class P1ParImpar {
    public static void main(String[] args) {
        Hilo hiloPar = new Hilo(2);
        Hilo hiloImpar = new Hilo(1);

        hiloImpar.setPriority(10);
        hiloPar.setPriority(1);

        hiloPar.start();
        hiloImpar.start();
    }
}
