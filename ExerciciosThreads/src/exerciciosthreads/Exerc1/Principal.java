/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package exerciciosthreads.Exerc1;

/*
1 - Crie uma classe que herda de Thread e faça com que ela imprima números de 1 até 5, 
com uma pausa de 1 segundo entre cada número.
*/

/**
 *
 * @author Otávio Baggio
 */
public class Principal {
    public static void main(String[] args) {
        Contador c = new Contador("Contadora");
        c.start();
        
    }
    
}
