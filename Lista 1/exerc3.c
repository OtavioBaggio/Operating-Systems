/*3 - Faça um programa em que dois processos concorrentes executam as ações a seguir.
Lembre-se de imprimir o PID de cada processo em cada impressão.
 Processo Pai:
Imprime os números de 1 a 50, com um intervalo de 2 segundos entre cada
número.
Ao terminar, imprime “Processo Pai finalizou”.
 Processo Filho1:
Imprime os números de 100 a 200, com um intervalo de 1 segundo entre
cada um.
Ao terminar, imprime “Filho1 finalizou”.
 Processo Filho2:
Imprime os números de 250 a 350, com um intervalo de 1 segundo entre
cada um.
Ao terminar, imprime “Filho2 finalizou”.
Verifique como acontece o escalonamento de processos na execução do exercício 3. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t f1, f2;

    // Cria o Filho 1
    f1 = fork();

    if (f1 < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (f1 == 0) {
        // Filho 1
        for (int i = 100; i <= 200; i++) {
            printf("Filho1 (PID %d): %d\n", getpid(), i);
            sleep(1);
        }
        printf("Filho1 finalizou (PID %d)\n", getpid());
        exit(0);
    }

    // Apenas o pai chega aqui → cria Filho 2
    f2 = fork();

    if (f2 < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (f2 == 0) {
        // Filho 2
        for (int i = 250; i <= 350; i++) {
            printf("Filho2 (PID %d): %d\n", getpid(), i);
            sleep(1);
        }
        printf("Filho2 finalizou (PID %d)\n", getpid());
        exit(0);
    }

    // Processo Pai
    for (int i = 1; i <= 50; i++) {
        printf("Pai (PID %d): %d\n", getpid(), i);
        sleep(2);
    }

    printf("Processo Pai finalizou (PID %d)\n", getpid());

    return 0;
}
