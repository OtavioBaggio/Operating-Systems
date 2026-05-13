package org.example;

public class Consumidor implements Runnable {

    private Buffer buffer;

    public Consumidor(Buffer buffer) {
        this.buffer = buffer;
    }

    public void run() {
        try {
            for (int i = 0; i < 10; i++) {
                buffer.consumir();
                Thread.sleep(1000);
            }
        }catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
