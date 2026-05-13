public class Conta {
    private int saldo = 100;

    public synchronized void sacar(int valor) {
        saldo -= valor;
        System.out.println("Saldo atual: " + saldo);

        if(saldo < 0){
            System.out.println("Saldo negativo!");
        }
    }

    public synchronized int getSaldo() {
        return saldo;
    }
}
