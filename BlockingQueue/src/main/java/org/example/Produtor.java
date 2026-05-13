package org.example;

public class Produtor implements Runnable {

    private Buffer buffer;

    public Produtor(Buffer buffer) {
        this.buffer = buffer;
    }

    @Override
    public void run() {
        try {
            for (int i = 0; i < 10; i++) {
                buffer.produzir(i);
                Thread.sleep(500);
            }
        }catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
