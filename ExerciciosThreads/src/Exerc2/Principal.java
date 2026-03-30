/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Exerc2;

/*
2 - Crie duas threads diferentes: uma deve imprimir “Thread A” contando de 1 até 5, 
e a outra “Thread B” também de 1 até 5. Execute ambas ao mesmo tempo e observe o resultado. 
Reflita: a ordem de execução será sempre a mesma?
*/

/**
 *
 * @author Otávio Baggio
 */
public class Principal {
    public static void main(String[] args) {
        
        // Reflita: a ordem de execução será sempre a mesma?
            // Não ocorre na mesma ordem, pois ambas ficam no estado Pronto. A partir daí, quem decide qual thread roda,
            // por quanto tempo, e quando troca é o escalonador do sistema operacional — e ele não garante ordem nem determinismo.
        
        ContadorThreads tA = new ContadorThreads("Thread A");
        ContadorThreads tB = new ContadorThreads("Thread B");
        
        tA.start();
        tB.start();
    }
    
}
