/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package exerciciosthreads.Exerc1;

/**
 *
 * @author Otávio Baggio
 */
public class Contador extends Thread{

    public Contador(String nome) {
        super(nome);
    }
    
    @Override
    public void run(){
        for(int i = 0; i <= 5; i++){
            System.out.println(getName() + " -> " + i);
            try{
                Thread.sleep(1000); //pausa de 1 segundo
            }catch(InterruptedException e){
                System.out.println(getName() + " foi interrompida!");
            }
        }
        System.out.println("TERMINOU!");
    }
    
    
    
}
