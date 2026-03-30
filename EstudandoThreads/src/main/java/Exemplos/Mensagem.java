/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Exemplos;

/**
 *
 * @author laboratorio
 */
public class Mensagem {
    private boolean pronta = false;
    
    public synchronized void esperarMensagem(){
        while(!pronta){
            try{
                System.out.println("Thread esperando mensagem...");
                wait();  // espera até alguém chamar notify
            }catch(InterruptedException e){
                e.printStackTrace();
            }
        }
        System.out.println("Mensagem recebida!");
    }
    
    public synchronized void enviarMensagem(){
        System.out.println("Preparando Mensagem...");
        pronta = true;
        notify();  // acorda a thread que está esperando
        System.out.println("Mensagem enviada!");
    }
    
}
