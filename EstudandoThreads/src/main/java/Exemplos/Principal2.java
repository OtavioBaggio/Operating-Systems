/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Exemplos;

/**
 *
 * @author laboratorio
 */
public class Principal2 {
    public static void main(String[] args) {
        
        Mensagem msg = new Mensagem();
        
        Thread t1 = new Thread(() -> {
            msg.esperarMensagem();
        });
        
        Thread t2 = new Thread(() -> {
           try{
               Thread.sleep(2000);
           }catch(InterruptedException e){
               e.printStackTrace();
           }
           msg.esperarMensagem();
        });
        
        t1.start();
        t2.start();
    }
    
}
