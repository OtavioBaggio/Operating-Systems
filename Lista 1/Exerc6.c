/*
6. a) Efetue a medida do tempo de execução deste programa, usando a função
gettimeofday, conforme o quadro 1. Compare os resultados obtidos, variando a
quantidade de processos. Qual das execuções apresentou melhor desempenho?
*/
#include <sys/time.h>

struct timeval tpI, tpF;
int sec, usec;

gettimeofday(&tpI, NULL);

// processamento aqui

gettimeofday(&tpF, NULL);

sec = tpF.tv_sec - tpI.tv_sec;
usec = tpF.tv_usec - tpI.tv_usec;

if (usec < 0) {
    usec += 1000000;
    sec -= 1;
}

printf("Tempo: %d s %d us\n", sec, usec);

// Geralmente: mais processos → mais rápido. Só até certo limite Depois piora.

/* Neste problema, existiu acesso concorrente aos dados pelos diferentes fluxos de execução?
Depende da implementação.

No exemplo acima:
Não há problema
Cada processo acessa parte diferente do vetor

Logo:

Não houve acesso concorrente problemático, pois cada processo manipulou regiões distintas da memória.
*/
