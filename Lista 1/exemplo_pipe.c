#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    int fd[2];

    if(pipe(fd) == -1){
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if(pid < 0){
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(pid == 0){
        // Código executado pelo processo filho
        close(fd[0]); // Fecha o lado de leitura do pipe

        char message[] = "Olá, pai!";
        write(fd[1], message, sizeof(message)); // Escreve no pipe

        close(fd[1]); // Fecha o lado de escrita do pipe
        exit(EXIT_SUCCESS);

    } else {
        // Código executado pelo processo pai
        close(fd[1]); // Fecha o lado de escrita do pipe

        char buffer[100];
        ssize_t bytes_lidos = read(fd[0], buffer, sizeof(buffer));

        if(bytes_lidos < 0){
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Pai recebeu: %s\n", buffer);

        close(fd[0]); // Fecha o lado de leitura do pipe
    }

    return 0;
}

