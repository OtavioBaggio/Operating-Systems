/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Exerc3;

import static Exerc3.ContadorCompartilhado.contador;

/*
3 - Crie um contador compartilhado entre duas threads. Cada uma deve incrementar esse contador 1000 vezes.
Ao final, imprima o valor do contador. Observe o resultado.
*/

/**
 *
 * @author Otávio Baggio
 */
public class Principal{
    public static void main(String[] args) throws InterruptedException {
        
        Thread tA = new Thread(() -> {
            for (int i = 0; i < 1000; i++) {
                contador++;
            }
        }, "Thread A");
 
        Thread tB = new Thread(() -> {
            for (int i = 0; i < 1000; i++) {
                contador++;
            }
        }, "Thread B");
        
        tA.start();
        tB.start();
 
        tA.join(); // espera tA terminar
        tB.join(); // espera tB terminar
        
        System.out.println("Valor final do contador: " + contador);
        System.out.println("Valor esperado: 2000");
        
    }
    
}
