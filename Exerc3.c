/*
2 – Escreva um programa formado por 3 threads, que executam um laço de repetição de
N interações. Neste laço, cada thread imprime sua identificação. 
A partir da execução do programa,
identifique como acontece o escalonamento dos threads.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 10  // Número de iterações por thread

void *executar(void *arg) {
    int id = *((int *)arg);

    for (int i = 1; i <= N; i++) {
        printf("Thread %d | Iteracao %2d | pthread_id: %lu\n",
               id, i, (unsigned long)pthread_self());
    }

    pthread_exit(NULL);
}

int main() {
    
    /*
    O programa foi executado 3 vezes. Em cada execução, a ordem das threads variou 
    (ex: Execução 1 → T1, T2, T3 | Execução 2 → T2, T1, T3), mas em todas elas cada 
    thread completou todas as suas 10 iterações seguidas antes de outra tomar o processador.
    */
    pthread_t threads[3];
    int ids[3] = {1, 2, 3};

    printf("=== Programa com 3 Threads (N = %d iteracoes) ===\n\n", N);

    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, executar, &ids[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\n=== Todas as threads finalizaram ===\n");
    return 0;
}