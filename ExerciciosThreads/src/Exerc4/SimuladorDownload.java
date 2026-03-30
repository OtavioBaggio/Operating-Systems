/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Exerc4;

/**
 *
 * @author Otávio Baggio
 */
public class SimuladorDownload extends Thread{
    
    private String arquivo;

    public SimuladorDownload(String arquivo) {
        this.arquivo = arquivo;
    }
    
    public void run(){
        System.out.println("Iniciando o download...");
        
        for(int progresso = 0; progresso <= 100; progresso += 10){
            System.out.println("Baixando " + arquivo + "... " + progresso + " %");
            
            try{
                Thread.sleep(500);
            }catch(InterruptedException e){
                System.out.println("Download Interrompido!");
                return;  //Se a thread for interrompida no meio, encerra o run invés de manter o loop do download
            }
        }
        
        System.out.println("Download concluído: " + arquivo);
    }
    
}
