#include <stdio.h>
#include "raylib.h"


void menuDesing(){  // Desing da home
    ClearBackground(MARROMDARK); // Limpar o plano de fundo para cor selecionada
    
    char nameWindowMain[20] = "Memory Game";
    
    DrawRectangleGradientV (00, 00, 900, 540, WHITE, MARROMDARK);  // fazendo um efeito grandiente no plano de fundo
    setNameWindow(nameWindowMain); // Colocando um nome na janela main

    DrawText("MEMORY GAME", 280, 180, 50, WHITE); // Desenha um texto (usando um fonte padrão) , param1 = Texto que eu quero escrever, param2 = Posição X, posição Y, param3 = Tamanho fonte, para4, Corte da fonte
    DrawText("START", 360, 280, 40, WHITE);
    DrawText("RECORDS", 360, 330, 40, WHITE);
    DrawText("EXIT", 360, 380, 40, WHITE);
    DrawText("©Gustavo Oliveira", 20, 600, 20, BLACK);
    DrawText("Github repository", 680, 600, 20, BLACK);
}


#ifndef HEARDESVICTORY_H_INCLUDED
#define HEARDESVICTORY_H_INCLUDED

void menuDesing();

#endif // HEARDESFUNCS_H_INCLUDED