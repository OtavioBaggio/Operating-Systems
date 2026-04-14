#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
3 – Escreva um programa formado por várias threads, que executam um laço de repetição de N
interações para incrementar em 1 uma variável compartilhada. Ao término da execução, 
verifique o valor final da variável compartilhada. 

*/


#define N_THREADS   5
#define N_ITERACOES 100000

long contador = 0;

void *incrementar(void *arg) {
    int id = *((int *)arg);

    for (int i = 0; i < N_ITERACOES; i++) {
        contador++;
    }

    printf("Thread %d finalizada.\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[N_THREADS];
    int ids[N_THREADS];
    long esperado = (long)N_THREADS * N_ITERACOES;

    printf("=== Incremento de Variavel Compartilhada ===\n");
    printf("Threads   : %d\n", N_THREADS);
    printf("Iteracoes : %d por thread\n", N_ITERACOES);
    printf("Esperado  : %ld\n\n", esperado);

    for (int i = 0; i < N_THREADS; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, incrementar, &ids[i]);
    }

    for (int i = 0; i < N_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\n=== Resultado Final ===\n");
    printf("Esperado  : %ld\n", esperado);
    printf("Obtido    : %ld\n", contador);
    printf("Diferenca : %ld\n", esperado - contador);

    if (contador != esperado)
        printf("\n[!] Race condition detectada — incrementos foram perdidos!\n");
    else
        printf("\n[!] Correto por acaso — pode falhar em outra execucao.\n");

    return 0;
}