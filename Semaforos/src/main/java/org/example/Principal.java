package org.example;

/*
Semáforos são uma ferramenta de sincronização utilizada para controlar o
acesso a recursos comuns em ambientes de programação concorrente.
• Eles podem ser binários (semelhante a um mutex) ou contar um número
específico de permissões que definem quantas threads podem acessar um
recurso simultaneamente.
 */
public class Principal {
    public static void main(String[] args) {

        Buffer bufferCompartilhado = new Buffer();
        Thread produtorThread = new Thread(new Produtor(bufferCompartilhado));
        Thread consumidorThread = new Thread(new Consumidor(bufferCompartilhado));

        produtorThread.start();
        consumidorThread.start();
    }
}