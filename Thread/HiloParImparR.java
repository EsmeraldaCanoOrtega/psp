class HiloParImparR implements Runnable {
    private int tipo;

    public HiloParImparR(int tipo) {
        this.tipo = tipo;
    }

    @Override
    public void run() {
        if (tipo == 1) {

            Thread.currentThread().setName("xx");
            System.out.println("HILO " + Thread.currentThread().getName() + " generando número par " + 1);
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


