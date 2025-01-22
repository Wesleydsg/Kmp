#include <stdio.h>
#include <getopt.h>
#include <sys/time.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <time.h>
#include "dados.h"
#include "forcaBruta.h"
#include "KMP.h"

void imprimeTempos(struct timeval start, struct timeval end, struct rusage usage) {
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    if (microseconds < 0) {
        seconds -= 1;
        microseconds += 1000000;
    }

    printf("\nTempo de relógio: %ld.%06ld segundos\n", seconds, microseconds);
    
    printf("Tempo de CPU em modo usuário: %ld.%06ld segundos\n",
           usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
    printf("Tempo de CPU em modo kernel: %ld.%06ld segundos\n\n",
           usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
}

int main(int argc, char** argv){

    struct timeval start, end;
    struct rusage usage;
    gettimeofday(&start, NULL);

    struct piano meuPiano;
    iniciaStruct(&meuPiano);

    abrirArquivo(argv[1]);

    switch (argv[2][0])
    {
    case '1':
        while(leTamanhos()){
            //printf("%d %d\n", tamanhoMusica, tamanhoTrecho);
            leMusicaTrecho(&meuPiano);

            // for(int i = 0; i < tamanhoMusica; i++){
            //     printf("%d ", musica[i]);
            // }
            // printf("\n");

            // for(int i = 0; i < tamanhoTrecho; i++){
            //     printf("%d ", trecho[i]);
            // }
            // printf("\n");

            kmp();

        }
        /* code */
        break;
    case '2':
        /* code */
        break;
    case '3':
        /* code */
        break;
    case '4':
        /* code */
        break;
    
    default:
        break;
    }

    fecharArquivo();

    gettimeofday(&end, NULL);
    getrusage(RUSAGE_SELF, &usage);

    imprimeTempos(start, end, usage);

    return 0;
}

// garantir linha
// cruzamento vai pegar inicio ao fim de linha