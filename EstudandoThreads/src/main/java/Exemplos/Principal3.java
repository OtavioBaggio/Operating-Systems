/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Exemplos;

/**
 *
 * @author laboratorio
 */
public class Principal3 {
    public static void main(String[] args) {
        
        DownloadThread download = new DownloadThread();
        download.start();
        
        try{
            download.join();    // espera a thread terminar
        }catch(InterruptedException e){
            e.printStackTrace();
        }
        
        System.out.println("Continuando execução da main...");
        
    }
    
}
