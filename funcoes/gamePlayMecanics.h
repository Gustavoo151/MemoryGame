#include <stdio.h>
#include "raylib.h"
#include <time.h>
#include <stdlib.h>
#include <stdlib.h>

// mecanica do jogo completo
#define coberto 0
#define descoberto 1

int map1[16] = {1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};
int map2[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


void shuffleVector(){  // Embaralhando vetor
    srand(time(NULL));
    for (int i = 1; i < 16; i++)
    {
        int r = rand() % 16;
        int temp = map1[i];
        map1[i] = map1[r];
        map1[r] = temp;
    }
}

void resetCards(){  // função que zera (vira para baixo todas as cartas) o os valores de map2
    for(int i =0; i < 16; i++)
        map2[i] = 0;
}

void resetAndStartsGameMecanics(){  // Função que tanto para inicar o jogo quanto resetar para jogar novamente
    shuffleVector();
    resetCards();
}


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
    if(verifica() == 1)
        return 3;
    else
        return 2;
}


void showCards(){
    if(map2[0] == 1){
        char numCard[0];
        itoa(map1[0], numCard,10);
        DrawText(numCard, 155, 200, 40, BLACK);
    }
   
    if(map2[1] == 1){
        char numCard[1];
        itoa(map1[1], numCard,10);
        DrawText(numCard, 300, 200, 40, BLACK);
    }   
    
    if(map2[2] == 1){
        char numCard[1];
        itoa(map1[2], numCard,10);
        DrawText(numCard, 450, 200, 40, BLACK);
    }
    
    if(map2[3] == 1){
        char numCard[1];
        itoa(map1[3], numCard,10);
        DrawText(numCard, 600, 200, 40, BLACK); 
    }
    
    if(map2[4] == 1){
        char numCard[1];
        itoa(map1[4], numCard,10);
        DrawText(numCard, 155, 300, 40, BLACK);
    }
    
    if(map2[5] == 1){
        char numCard[1];
        itoa(map1[5], numCard,10);
        DrawText(numCard, 300, 300, 40, BLACK);
    }
    
    if(map2[6] == 1){
        char numCard[1];
        itoa(map1[6], numCard,10);
        DrawText(numCard, 450, 300, 40, BLACK);
    }
        
    if(map2[7] == 1){
        char numCard[1];
        itoa(map1[7], numCard,10);
        DrawText(numCard, 600, 300, 40, BLACK);
    }
    
    if(map2[8] == 1){
        char numCard[1];
        itoa(map1[8], numCard,10);
        DrawText(numCard, 155, 400, 40, BLACK);
    }
    
    if(map2[9] == 1){
        char numCard[1];
        itoa(map1[9], numCard,10);
        DrawText(numCard, 300, 400, 40, BLACK);
    }
    
    if(map2[10] == 1){
        char numCard[1];
        itoa(map1[10], numCard,10);
        DrawText(numCard, 450, 400, 40, BLACK);
    }
    
    if(map2[11] == 1){
        char numCard[1];
        itoa(map1[10], numCard,10);
        DrawText(numCard, 600, 400, 40, BLACK);
    }
    
    if(map2[12] == 1){
        char numCard[1];
        itoa(map1[12], numCard,10);
        DrawText(numCard, 155, 500, 40, BLACK);
    }
    
    if(map2[13] == 1){
        char numCard[1];
        itoa(map1[13], numCard,10);
        DrawText(numCard, 300, 500, 40, BLACK);
    }
    
    if(map2[14] == 1){
        char numCard[1];
        itoa(map1[14], numCard,10);
        DrawText(numCard, 450, 500, 40, BLACK);
    }
    
    if(map2[15] == 1){
        char numCard[1];
        itoa(map1[15], numCard,10);
        DrawText(numCard, 600, 500, 40, BLACK); 
    }        
}

void checkCards(){
    
    if ((contJogadas == verificaPares) && (contJogadas % 2 == 0)){  // Erro na verificaçaõ
        if((contJogadas % 2 == 0) && (map1[positionOne] != map1[positionTwo])){
            map2[positionOne] = coberto;
            map2[positionTwo] = coberto;
          //  DrawText("Errou", 360, 200, 40, WHITE);
            contJogadas = contJogadas - 2;
        }
        else{
          //  DrawText("BOAAAAAAAA", 360, 280, 40, WHITE);
            verificaPares = verificaPares + 2;
        }
    }    
}


#ifndef HEARDESGAMEPLAY_H_INCLUDED
#define HEARDESGAMEPLAY_H_INCLUDED
 

int verifica();
void showCards();
int gamePlay(int bottonClick);
void shuffleVector();
void resetAndStartsGameMecanics();


#endif // HEARDESFUNCS_H_INCLUDED