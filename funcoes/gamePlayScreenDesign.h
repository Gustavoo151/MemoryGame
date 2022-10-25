#include <stdio.h>
#include "raylib.h"


void gamePlayDesing(){  // função que cria os textos da gamePlay Screen
        
    SetWindowTitle("Memory Game"); // Colocando um nome na janela gamePlay
    
    DrawText("MEMORY GAME", 275, 100, 40, WHITE);
    DrawText("HOME", 780, 360, 35, WHITE);
    DrawText("SAVE", 780, 410, 35, WHITE);
    DrawText("EXIT", 780, 440, 35, WHITE);
    
    showCards();   // Chamando a função que mostras as cartas viradas
    checkCards();  // Chamando função que verificaos se as cartas deram match
}


// Return: True para sinalizar que o botão foi acionado
int exitSave(){  // Verifica se o botao exit/save foi clicado para finalizar o game 
    int opcClickSave = clickSaveGamePlay();
    
    if (opcClickSave == 1){ 
        continueGameOpc(opcClickSave); // Passando o retorno da função saveGamePlay para o arquivo continueOption.txt
        return 1;
    }
}

#ifndef HEARDESGAMEPLAYSCREEN_H_INCLUDED
#define HEARDESGAMEPLAYSCREEN_H_INCLUDED

int exitSave();
void gamePlayDesing();

#endif // HEARDESFUNCS_H_INCLUDED