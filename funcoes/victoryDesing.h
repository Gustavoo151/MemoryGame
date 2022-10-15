#include <stdio.h>
#include "raylib.h"


void victoryDesing(){  // Função que mostra o texto da tela de vitoria
    ClearBackground(MARROMDARK);
    DrawRectangleGradientV (00, 00, 900, 350, WHITE, MARROMDARK);  // fazendo um efeito grandiente no plano de fundo
    char moves[20] = "20 - Moves";
    DrawText("VICTORY", 260, 180, 80, GOLD);
    DrawText(moves, 320, 320, 40, RAYWHITE);
    DrawText("BACK", 380, 420, 30, WHITE);
}


#ifndef HEARDESVICTORY_H_INCLUDED
#define HEARDESVICTORY_H_INCLUDED

void victoryDesing();

#endif // HEARDESFUNCS_H_INCLUDED