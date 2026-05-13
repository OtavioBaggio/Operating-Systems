package org.example;

public class BufferCircular {
    private final int[] buffer;
    private int front;  // indica a posição do próximo item a ser consumida
    private int rear;   // indica a posição do próximo item a ser produzido
    private int count = 0;  // número de itens no buffer

    public BufferCircular(int size) {
        buffer = new int[size];
    }

    public synchronized void put(int value) throws InterruptedException {
        while (count == buffer.length) {
            wait();     // Buffer cheio, espera até o consumidor consumir algum item
        }
        buffer[rear] = value;
        rear = (rear + 1) % buffer.length;
        count++;
        notifyAll();    // Notifica as threads que estão esperando consumir
    }

    public synchronized int get() throws InterruptedException {
        while (count == 0) {
            wait();     // Buffer vazio, espera até o produtor produzir algum item
        }
        int result = buffer[front];
        front = (front + 1) % buffer.length;
        count--;
        notifyAll();    // Notifica as threads que estão esperando produzir
        return result;
    }
}
