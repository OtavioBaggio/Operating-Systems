/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Exerc2;

/**
 *
 * @author Otávio Baggio
 */
public class ContadorThreads extends Thread{

    public ContadorThreads(String nome) {
        super(nome);
    }
    
    @Override
    public void run(){
        for(int i = 0; i < 5; i++){
            System.out.println(getName() + " -> " + i);
            try{
                Thread.sleep(500);
            }catch(InterruptedException e){
                System.out.println(getName() + " foi interrompida!");
            }
        }
        System.out.println(getName() + " TERMINOU!");
    }
    
    
}
