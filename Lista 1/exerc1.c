/*1 – Crie um programa com dois processos. As medidas de um terreno retangular devem ser
lidas. O processo Filho deve calcular a área do terreno e o processo Pai o perímetro. Todos
os resultados obtidos devem ser mostrados ao usuário
*/
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    float largura, comprimento;

    printf("Digite a largura do terreno: ");
    scanf("%f", &largura);

    printf("Digite o comprimento do terreno: ");
    scanf("%f", &comprimento);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Processo filho ->  calcula área
        float area = largura * comprimento;
        printf("Filho: Área do terreno = %.2f\n", area);
    } else {
	wait(NULL);
        // Processo pai ->  calcula perímetro
        float perimetro = 2 * (largura + comprimento);
        printf("Pai: Perímetro do terreno = %.2f\n", perimetro);
    }

    return 0;
}
