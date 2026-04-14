/*
1 – Crie um programa com dois threads. As medidas de um terreno retangular devem ser lidas. Um
thread deve calcular a área do terreno e outro o perímetro. Todos os resultados obtidos devem ser
mostrados ao usuário.
*/

#include <stdio.h>
#include <pthread.h>

// Estrutura para passar os dados
typedef struct {
    float largura;
    float comprimento;
} Terreno;

// Função da thread que calcula a área
void* calcula_area(void* arg) {
    Terreno* t = (Terreno*) arg;
    float area = t->largura * t->comprimento;

    printf("Área do terreno: %.2f\n", area);
    return NULL;
}

// Função da thread que calcula o perímetro
void* calcula_perimetro(void* arg) {
    Terreno* t = (Terreno*) arg;
    float perimetro = 2 * (t->largura + t->comprimento);

    printf("Perímetro do terreno: %.2f\n", perimetro);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    Terreno terreno;

    // Entrada de dados
    printf("Digite a largura do terreno: ");
    scanf("%f", &terreno.largura);

    printf("Digite o comprimento do terreno: ");
    scanf("%f", &terreno.comprimento);

    // Criação das threads
    pthread_create(&t1, NULL, calcula_area, &terreno);
    pthread_create(&t2, NULL, calcula_perimetro, &terreno);

    // Espera as threads terminarem
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}