/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Exemplos;

/**
 *
 * @author laboratorio
 */
public class DownloadThread extends Thread{
    
    public void run(){
        System.out.println("Iniciando download...");
        
        try{
            Thread.sleep(3000);
        }catch(InterruptedException e){
        e.printStackTrace();
        }
        
        System.out.println("Download concluido!");
    }
    
}
