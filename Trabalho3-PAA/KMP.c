#include "dados.h"
#include "KMP.h"

void calculaPrefixo(int* prefixo) {
    int j = 0; // comprimento
    prefixo[0] = 0; // padrão do kmp

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
    int k = 0, j = 1, diferenca = trecho[0] - musica[0], difTemp;

    if (diferenca < 0) diferenca = diferenca + 12;
    
    for (int i = 1; i < tamanhoMusica; i++) {

        difTemp = trecho[j] - musica[i];
        if (difTemp < 0) difTemp = difTemp + 12;

        while (j > 0 && diferenca != difTemp) {
            j = prefixo[j - 1];
            diferenca = trecho[j] - musica[i];
            if (diferenca < 0) diferenca = diferenca + 12;
        }
        if (diferenca == difTemp) {
            j++;
        }
        if (j == tamanhoTrecho) {
            k = 1;
            printf("achei");
        }
    }

    free(prefixo);
}