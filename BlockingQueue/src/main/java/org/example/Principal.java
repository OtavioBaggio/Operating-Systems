package org.example;

/*
Implementação Manual:           BlockingQueue:
wait()                             automático
notify()                           automático
semáforos                          interno
maior complexidade                menor complexidade
mais propensa a erros              mais segura
 */
public class Principal {
    public static void main(String[] args) {

        Buffer buffer = new Buffer();

        Thread produtor = new Thread(new Produtor(buffer));

        Thread consumidor = new Thread(new Consumidor(buffer));

        produtor.start();
        consumidor.start();
    }
}