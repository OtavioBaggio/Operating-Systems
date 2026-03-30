/* 2 – Escreva um programa formado por 3 processos concorrentes, que executam um laço de
repetição de N interações. Neste laço, cada processo imprime sua identificação. A partir da
execução do programa, identifique como acontece o escalonamento dos processos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int N = 10; // número de interações

    pid_t p1, p2;

    // Cria o segundo processo
    p1 = fork();

    if (p1 < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (p1 == 0) {
        // Processo Filho 1
        for (int i = 0; i < N; i++) {
            printf("Processo Filho 1 - PID %d - Iteracao %d\n", getpid(), i);
        }
    } else {
        // Ainda no pai → cria o terceiro processo
        p2 = fork();

        if (p2 < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (p2 == 0) {
            // Processo Filho 2
            for (int i = 0; i < N; i++) {
                printf("Processo Filho 2 - PID %d - Iteracao %d\n", getpid(), i);
            }
        } else {
            // Processo Pai
            for (int i = 0; i < N; i++) {
                printf("Processo Pai - PID %d - Iteracao %d\n", getpid(), i);
            }
        }
    }

    return 0;
}
