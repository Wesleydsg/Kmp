#include "dados.h"

FILE* arquivoMusical = NULL;
int* musica;
int* trecho;
int tamanhoMusica;
int tamanhoTrecho;

// Função para inicializar a struct
void iniciaStruct(struct piano* p) {
    // Array temporário de strings
    char* notasTemp[] = {"A", "A#", "Ab", "B", "B#", "Bb", "C", "C#", "Cb", 
                         "D", "D#", "Db", "E", "E#", "Eb", "F", "F#", "Fb", 
                         "G", "G#", "Gb"};

    int conversaoTemp[] = {2, 3, 1, 4, 5, 3, 5, 6, 4, 7, 8, 6, 9, 10, 8, 10, 11, 9, 12, 1, 11};

    // Inicializa o array dentro da struct
    for (int i = 0; i < 21; i++) {
        p->notas[i] = notasTemp[i];
        p->conversao[i] = conversaoTemp[i]; 
    }
}

void abrirArquivo(const char *arquivo){
    arquivoMusical = fopen(arquivo, "r");
    if (arquivoMusical == NULL) {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }
}

void fecharArquivo(){
    fclose(arquivoMusical);
    arquivoMusical = NULL;
}

bool leTamanhos(){
    char *linha = NULL;
    size_t tamanho = 0;

    getline(&linha, &tamanho, arquivoMusical); // Usa getline para ler a linha de tamanho desconhecido
    sscanf(linha, "%d %d", &tamanhoMusica, &tamanhoTrecho); // Converte a linha lida em dois números inteiros
    
    free(linha); // Libera o buffer alocado por getline
    if(tamanhoMusica != 0 && tamanhoTrecho != 0) return true;

    return false;
}

void leMusicaTrecho(struct piano* p) {
    musica = (int*)malloc(tamanhoMusica * sizeof(int));

    trecho = (int*)malloc(tamanhoTrecho * sizeof(int));

    char *linha = NULL;
    size_t tamanho = 0;
    char *elemento;

    //parte para pegar a musica
    getline(&linha, &tamanho, arquivoMusical);

    elemento = strtok(linha, " \n");

    int index = 0;
    while (elemento != NULL) {
        for(int i = 0; i < 21; i++){
            if(strcmp(elemento, p->notas[i]) == 0){
                musica[index] = p->conversao[i];
                index++;
            }
        }
        elemento = strtok(NULL, " \n");
    }

    //parte para pegar o trecho
    getline(&linha, &tamanho, arquivoMusical);

    elemento = strtok(linha, " \n");

    index = 0;
    while (elemento != NULL) {
        for(int i = 0; i < 21; i++){
            if(strcmp(elemento, p->notas[i]) == 0){
                trecho[index] = p->conversao[i];
                index++;
            }
        }
        elemento = strtok(NULL, " \n");
    }

}