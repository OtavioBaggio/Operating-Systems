package org.example;

import java.util.LinkedList;
import java.util.Queue;
import java.util.concurrent.Semaphore;

/*
Um semáforo mantém um conjunto de permissões:
• Acquire (adquirir): uma thread tenta obter uma permissão. Se nenhuma
permissão estiver disponível, a thread é bloqueada até que uma permissão
seja liberada por outra thread.
• Release (liberar): uma thread libera uma permissão, tornando-a disponível
para outra thread que possa estar esperando
 */

public class Buffer {
    private Queue<Integer> queue = new LinkedList<Integer>();
    private static final int CAPACITY = 5;
    private Semaphore semFull = new Semaphore(0);
    private Semaphore semEmpty = new Semaphore(CAPACITY);

    public void put(int item) throws InterruptedException {
        semEmpty.acquire();     // Adquire um espaço vazio;
        synchronized (this) {   // Significa que a partir DAQUI vai ser synchronized
            queue.add(item);
            System.out.println("Produzido: " + item);
        }
        semFull.release();  // Libera um espaço cheio
    }

    public int get() throws InterruptedException {
        semFull.acquire();  // adquire espaço cheio
        int item;
        synchronized (this) {
            item = queue.poll();
            System.out.println("Consumido: " + item);
        }
        semEmpty.release();     // Libera um espaço vazio
        return item;
    }
}
