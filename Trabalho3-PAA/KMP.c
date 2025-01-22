#include "dados.h"
#include "KMP.h"

void calculaPrefixo(int* prefixo) {
    int j = 0;
    prefixo[0] = 0;

    for (int i = 1; i < tamanhoTrecho; i++) {
        while (j > 0 && trecho[i] != trecho[j]) {
            j = prefixo[j - 1];
        }
        if (trecho[i] == trecho[j]) {
            j++;
        }
        prefixo[i] = j;
    }
}

void kmp() {
    int* prefixo = (int*)malloc(tamanhoTrecho * sizeof(int));
    calculaPrefixo(prefixo);
    int k = 0;

    int j = 0;
    for (int i = 0; i < tamanhoMusica; i++) {
        while (j > 0 && musica[i] != trecho[j]) {
            j = prefixo[j - 1];
        }
        if (musica[i] == trecho[j]) {
            j++;
        }
        if (j == tamanhoTrecho) {
            printf("ACHEI PORRA\n");
            k = 1;
        }
    }
    if(k == 0) printf("Peru\n");

    free(prefixo);
}