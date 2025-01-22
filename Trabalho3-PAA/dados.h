#ifndef DADOS_H
#define DADOS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

extern FILE* arquivoMusical;
extern int* musica;
extern int* trecho;
extern int tamanhoMusica;
extern int tamanhoTrecho;

struct piano{
    char* notas[21];
    int conversao[21];
};

void iniciaStruct(struct piano* p);
void abrirArquivo(const char *arquivo);
void fecharArquivo();
bool leTamanhos();
void leMusicaTrecho(struct piano* p);

#endif