public class Buffer {
    private int conteudo;
    private boolean disponivel = false;

    public synchronized void set(int valor) {
        while(disponivel) {
            try{
                wait();     // Espera até o buffer estar vazio
            }catch(InterruptedException e){ }
        }
    }

    public synchronized int get() {
        while(!disponivel) {
            try{
                wait();     //Espera até o buffer estar cheio
            }catch(InterruptedException e){ }
        }
        disponivel = false;
        notifyAll();        // Notifica que o buffer agora está vazio
        return conteudo;
    }
}
