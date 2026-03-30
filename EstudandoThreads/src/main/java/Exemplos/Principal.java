/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Exemplos;

import com.sun.tools.javac.Main;

/**
 *
 * @author laboratorio
 */
public class Principal extends Thread{
    public Principal(String str){
        super(str);
    }
    
    @Override
    public void run(){
        for(int i = 0; i< 30; i++){
            System.out.println(i + " " + getName());
        }
        System.out.println(getName() + " TERMINOU!");
    }
    
    public static void main(String[] args){
        Principal Thread1 = new Principal("Primeira");
        Principal Thread2 = new Principal("Segunda");
        Thread1.start();
        Thread2.start();
        for(int i = 0; i < 20; i++){
            System.out.println(i + " Trhead Principal");
            System.out.println("Thread PRINCIPAL, término de execução");
        }
    }
            

    
        
}    
    

