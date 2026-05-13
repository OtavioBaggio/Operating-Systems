package org.example;

public class Consumidor implements Runnable {
    private Buffer buffer;

    public Consumidor(Buffer buffer) {
        this.buffer = buffer;
    }

    @Override
    public void run() {
        try {
            for (int i = 0; i < 10; i++) {
                buffer.get();
                Thread.sleep(1000);     // Simula tempo de consumo
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
