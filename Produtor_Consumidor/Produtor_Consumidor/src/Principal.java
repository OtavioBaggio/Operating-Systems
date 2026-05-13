//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Principal {
    public static void main(String[] args) {

        Buffer bufferCompartilhado = new Buffer();
        Thread produtorThread = new Thread(new Produtor(bufferCompartilhado));
        Thread consumidorThread = new Thread(new Consumidor(bufferCompartilhado));

        produtorThread.start();
        consumidorThread.start();
    }
}