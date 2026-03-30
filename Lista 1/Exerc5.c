/*
5 –Desenvolva um algoritmo para efetuar a soma dos dois vetores e mostrar o vetor
resultante, com mais de um processo para efetuar a soma dos vetores;
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 10

int main() {
    int A[N], B[N], C[N];

    // Inicialização
    for (int i = 0; i < N; i++) {
        A[i] = i;
        B[i] = i * 2;
    }

    pid_t pid = fork();

    if (pid == 0) {
        // Filho calcula segunda metade
        for (int i = N/2; i < N; i++) {
            C[i] = A[i] + B[i];
        }
        printf("Filho terminou\n");
    } else {
        // Pai calcula primeira metade
        for (int i = 0; i < N/2; i++) {
            C[i] = A[i] + B[i];
        }

        wait(NULL);

        printf("Resultado:\n");
        for (int i = 0; i < N; i++) {
            printf("%d ", C[i]);
        }
    }

    return 0;
}
