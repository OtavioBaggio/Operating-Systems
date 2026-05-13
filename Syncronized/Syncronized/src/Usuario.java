public class Usuario extends Thread {
    Conta conta;

    public Usuario(Conta conta) {
        this.conta = conta;
    }

    public void run() {
        for (int i = 0; i < 10; i++) {
            conta.sacar(10);
            //System.out.println(Thread.currentThread().getName() + ": Saque de " + conta.getSaldo());
        }
    }
}
