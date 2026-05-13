package org.example;

/*
Estrutura da biblioteca java.util.concurrent
• Implementa automaticamente:
• Sincronização
• espera por espaço livre
• espera por itens disponíveis
• comunicação entre threads
• Muito utilizada no desenvolvimento concorrente moderno

  • Inserção
  • fila.put(item);
  • Se a fila estiver cheia:
    • a thread espera automaticamente

  • Remoção
   • fila.take();
   • Se a fila estiver vazia:
    • a thread espera automaticamente
 */
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class Buffer {

    private BlockingQueue<Integer> fila =
            new ArrayBlockingQueue<Integer>(5);

    public void produzir(int valor) throws InterruptedException {
        fila.put(valor);

        System.out.println("Produzido: " + valor);
    }

    public void consumir() throws InterruptedException {
        int valor = fila.take();

        System.out.println("Consumido: " + valor);
    }
}
