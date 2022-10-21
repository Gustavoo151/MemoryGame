#include <stdio.h>
#include "raylib.h"
#include <time.h>
#include <stdlib.h>


void shuffleVector(int *vet, int vetSize){  // Embaralhando vetor
    srand(time(NULL));
    for (int i = 1; i < vetSize; i++)
    {
        int r = rand() % vetSize;

        int temp = vet[i];
        vet[i] = vet[r];
        vet[r] = temp;
    }
}

// mecanica do jogo completo
#define coberto 0
#define descoberto 1

int map1[16] = {1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};
int map2[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int verifica(){  // Função que verifica os pares
    int combinations = 0;
    for (int i = 0; i <16; i++){
        if (map2[i] == 1)
            combinations++;
    }
    if (combinations == 16){
        printf("Fim de jogo");
        return 1;
    }
    return 0;
}

int contJogadas = 0;
int positionOne, positionTwo;
int verificaPares = 2;

int gamePlay(int bottonClick){ // Função que verifica se os mach e rebece os valores da função click mouse
    
    if((map2[bottonClick] == coberto) && (contJogadas % 2 == 0)){
            map2[bottonClick] = descoberto;
            positionOne = bottonClick;
            contJogadas ++;
    }
  
    else if((map2[bottonClick] == coberto) && (contJogadas % 2 == 1)){
        map2[bottonClick] = descoberto;
        positionTwo = bottonClick;
        contJogadas ++;
    }
    
    if ((contJogadas == verificaPares) && (contJogadas % 2 == 0)){  // Erro na verificaçaõ
        if((contJogadas % 2 == 0) && (map1[positionOne] != map1[positionTwo])){
            map2[positionOne] = coberto;
            map2[positionTwo] = coberto;
            DrawText("Errou", 360, 200, 40, WHITE);
            contJogadas = contJogadas - 2;
        }
        else{
            DrawText("BOAAAAAAAA", 360, 280, 40, WHITE);
            verificaPares = verificaPares + 2;
        }
    }
 
    if(verifica() == 1)
        return 3;
    else
        return 2;
}

#ifndef HEARDESGAMEPLAY_H_INCLUDED
#define HEARDESGAMEPLAY_H_INCLUDED
 
void shuffleVector(int *vet, int vetSize);
int verifica();

int gamePlay(int bottonClick);


#endif // HEARDESFUNCS_H_INCLUDED