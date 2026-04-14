#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/*
4 – Escreva um programa com duas threads que compartilham um vetor de inteiros tamanho 5 e uma
outra variável inteira que conta quantos elementos há no vetor. Uma das threads escreve um 
dado no vetor e a outra remove um dado no vetor. A execução das threads é contínua.
a) Verifique a execução do programa
    As duas threads rodam continuamente em paralelo com ritmos diferentes
    
b) Os valores apresentados nos dados compartilhados são corretos
    Estão, mas por causa dos sleeps colocados, sem isso ocorreria race condition
    
c) Neste problema, as threads precisam ser sincronizadas?
    Sim, caso haja vetores cheios ou vetor vazio(ele ia pegar uma posicao invalida)
*/

#define TAM_VETOR  5
#define N_OPERACOES 10

// ── Dados compartilhados ─────────────────────────────────────
int vetor[TAM_VETOR];
int contador = 0;  // quantos elementos há no vetor

// ── Thread escritora ─────────────────────────────────────────
void *escritora(void *arg) {
    int valor = 1;

    for (int op = 0; op < N_OPERACOES; op++) {
        if (contador < TAM_VETOR) {
            vetor[contador] = valor;
            contador++;
            printf("[ESCRITORA] Inseriu %2d | contador = %d | vetor: ", valor, contador);
            for (int i = 0; i < contador; i++) printf("%d ", vetor[i]);
            printf("\n");
            valor++;
        } else {
            printf("[ESCRITORA] Vetor cheio, aguardando...\n");
            op--;  // tenta de novo
        }
        usleep(100000);  // 100ms
    }

    pthread_exit(NULL);
}

// ── Thread removedora ────────────────────────────────────────
void *removedora(void *arg) {
    for (int op = 0; op < N_OPERACOES; op++) {
        if (contador > 0) {
            int removido = vetor[0];

            // desloca elementos
            for (int i = 0; i < contador - 1; i++)
                vetor[i] = vetor[i + 1];
            contador--;

            printf("[REMOVEDORA] Removeu %2d | contador = %d | vetor: ", removido, contador);
            for (int i = 0; i < contador; i++) printf("%d ", vetor[i]);
            printf("\n");
        } else {
            printf("[REMOVEDORA] Vetor vazio, aguardando...\n");
            op--;  // tenta de novo
        }
        usleep(150000);  // 150ms — ritmo diferente da escritora
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t t_escritora, t_removedora;

    printf("=== Vetor Compartilhado SEM sincronizacao ===\n");
    printf("Tamanho do vetor : %d\n", TAM_VETOR);
    printf("Operacoes        : %d por thread\n\n", N_OPERACOES);

    pthread_create(&t_escritora,  NULL, escritora,  NULL);
    pthread_create(&t_removedora, NULL, removedora, NULL);

    pthread_join(t_escritora,  NULL);
    pthread_join(t_removedora, NULL);

    printf("\n=== Estado final ===\n");
    printf("contador = %d\n", contador);
    printf("vetor    : ");
    for (int i = 0; i < contador; i++) printf("%d ", vetor[i]);
    printf("\n");

    return 0;
}