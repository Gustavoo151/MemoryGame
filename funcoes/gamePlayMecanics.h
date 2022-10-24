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


void resetCards(){  // função que zera (vira para baixo todas as cartas) os valores do cardsAux
    for(int i =0; i < 16; i++)
        cardsAux[i] = 0;
}


void resetAndStartsGameMecanics(){  // Função que reseta o jogar
    shuffleVector();
    resetCards();
}


int verifica(){  // Função que verifica os pares e rotorna o valor para indicar o fim do jogo
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
                    DrawText(numCard,(i*150) + 150, 200, 40, BLACK);

                else if ((i < 8) && (i > 3))           
                    DrawText(numCard, ((i-4)*150) + 150, 300, 40, BLACK);  
               
                else if ((i < 12) && (i > 7))
                    DrawText(numCard, ((i-8)*150) + 150, 400, 40, BLACK);  
     
                else if ((i < 16) && (i > 11))
                    DrawText(numCard, (i-12) * 150 + 150, 500, 40, BLACK);  
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
int gamePlay(int bottonClick);
void shuffleVector();
void resetAndStartsGameMecanics();
void showCards1();

#endif // HEARDESFUNCS_H_INCLUDED