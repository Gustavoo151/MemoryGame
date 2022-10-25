#include <stdio.h>
#include "raylib.h"
#include <time.h>
#include <stdlib.h>

// mecanica do jogo completo
#define coberto 0
#define descoberto 1

int cards[16] = {1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};
int cardsAux[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


void shuffleVector(){  // Funcao que embaralha vetor
    srand(time(NULL));
    for (int i = 1; i < 16; i++)
    {
        int r = rand() % 16;
        int temp = cards[i];
        cards[i] = cards[r];
        cards[r] = temp;
    }
}


void loadSave(){  // Funcao que carrega os dados salvos para o jogo 
    FILE *cardsSaveArchive;
    FILE *cardsAuxSave;

    cardsSaveArchive = fopen("saveGameData/saveDadosCards.txt", "r");
    cardsAuxSave = fopen("saveGameData/saveDadosCardsAux.txt", "r");

    if (cardsSaveArchive != NULL)
        fscanf(cardsSaveArchive,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &cards[0], &cards[1], &cards[2], &cards[3], &cards[4], &cards[5], &cards[6], &cards[7], &cards[8], &cards[9], &cards[10], &cards[11], &cards[12], &cards[13], &cards[14], &cards[15]);   

    if (cardsAuxSave != NULL)
        fscanf(cardsAuxSave,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &cardsAux[0], &cardsAux[1], &cardsAux[2], &cardsAux[3], &cardsAux[4], &cardsAux[5], &cardsAux[6], &cardsAux[7], &cardsAux[8], &cardsAux[9], &cardsAux[10], &cardsAux[11], &cardsAux[12], &cardsAux[13], &cardsAux[14], &cardsAux[15]);   
}


void resetCards(){  // função que zera (vira para baixo todas as cartas) os valores do cardsAux
    for(int i =0; i < 16; i++)
        cardsAux[i] = 0;
}


void resetAndStartsGameMecanics(){  // Função que reseta o jogar
    shuffleVector();
    resetCards();
    saveGameProgress(cards, cardsAux);  // Chamando funcao que salva o progresso do jogo
}


int verifica(){  // Função que verifica os pares e rotorna o valor para indicar o fim do jogo
    saveGameProgress(cards, cardsAux);  // Chamando funcao que salva o progresso do jogo
    int combinations = 0;
    for (int i = 0; i <16; i++){
        if (cardsAux[i] == 1)
            combinations++;
    }
    if (combinations == 16)
        return 1;
    return 0;
}

int contJogadas = 0;  // Contador de jogadas para indicar se e a primeira ou segunda carta que foi clicada
int positionOne, positionTwo;  // Variaveis que salva os valores da posição um e dois para fazer a verificaçao se deram mach
int verificaPares = 2; // Verica quanto pares ja foram feitos no game


int gamePlay(int bottonClick){ // Função que verifica se os mach e rebece os valores da função click mouse   
    if((cardsAux[bottonClick] == coberto) && (contJogadas % 2 == 0)){
            cardsAux[bottonClick] = descoberto;
            positionOne = bottonClick;
            contJogadas ++;
    }
    else if((cardsAux[bottonClick] == coberto) && (contJogadas % 2 == 1)){
        cardsAux[bottonClick] = descoberto;
        positionTwo = bottonClick;
        contJogadas ++;
    }
    if(verifica() == 1) // Verifica se todos os pares deram mach e rotorna o valor para tela de vitoria
        return 3; // Valor para abrir a tela de vitoria
    else
        return 2;  // Valor da tela de gamePlay
}


void showCards(){   // Funcao que mostra as cartas clicada na tela
    for(int i = 0; i < 16; i++){
            if(cardsAux[i] == 1){
                char numCard[1];
                itoa(cards[i], numCard,10);  // Transformar um int em char
                
                if (i < 4)
                    DrawText(numCard,(i*150) + 175, 200, 50, BLACK);

                else if ((i < 8) && (i > 3))           
                    DrawText(numCard, ((i-4)*150) + 175, 300, 50, BLACK);  
               
                else if ((i < 12) && (i > 7))
                    DrawText(numCard, ((i-8)*150) + 175, 400, 50, BLACK);  
     
                else if ((i < 16) && (i > 11))
                    DrawText(numCard, (i-12) * 150 + 175, 500, 50, BLACK);  
        }
    }       
}


void checkCards(){  // Função que verifica se os pares deram mach 
    if ((contJogadas == verificaPares) && (contJogadas % 2 == 0)){  // Erro na verificaçaõ
        
        if((contJogadas % 2 == 0) && (cards[positionOne] != cards[positionTwo])){
            cardsAux[positionOne] = coberto;
            cardsAux[positionTwo] = coberto;
            contJogadas = contJogadas - 2;
        }
        else{            
            verificaPares = verificaPares + 2;
        }
        
    } 
}

#ifndef HEARDESGAMEPLAYMECANICS_H_INCLUDED
#define HEARDESGAMEPLAYMECANICS_H_INCLUDED
 
int verifica();
void showCards();
void loadSave();
int gamePlay(int bottonClick);
void shuffleVector();
void resetAndStartsGameMecanics();
void showCards1();

#endif // HEARDESFUNCS_H_INCLUDED