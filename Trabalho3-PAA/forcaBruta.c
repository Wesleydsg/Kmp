#include "forcaBruta.h"
#include "dados.h"

void resolve1(){
    int index;
    bool r = false;
    int diferenca = 0;
    int difTemp = 0;
    int ind = 0;

    if(tamanhoTrecho == 1){
        r = true;
        ind = 0;
    }

    for(int i = 0; i < tamanhoMusica && tamanhoTrecho > 1; i++){
        if(tamanhoMusica - i < tamanhoTrecho) break;

        index = 1;

        for(int j = i+1; index < tamanhoTrecho; j++){
            diferenca = musica[j] - musica[j-1];
            difTemp = trecho[index] - trecho[index-1];

            if (diferenca < 0) diferenca = diferenca + 12;
            if (difTemp < 0) difTemp = difTemp + 12;

            if(diferenca != difTemp){
                r = false;
                break;
            }

            r = true;
            index++;
        }

        if(r){
            ind = i;
            break;
        }
    }

    if(r) printf("S %d\n", ind);
    else printf("N\n");

    return;
}