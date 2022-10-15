#include <stdio.h>
#include "raylib.h"

void defeatDesing(){  // Deseing telada de derrota
    ClearBackground(MARROMDARK);
    
    char nameWindowDefeat[10] = "DEFEAT";
    setNameWindow(nameWindowDefeat); // Colocando um nome na janela defeat
    
    DrawRectangleGradientV (00, 00, 900, 540, WHITE, MARROMDARK);  // fazendo um efeito grandiente no plano de fundo
    DrawText("DEFEAT", 300, 180, 80, WHITE);
    DrawText("PLAY AGAIN", 350,320, 30, WHITE);
    DrawText("BACK", 350,380, 30, WHITE);
}


#ifndef HEARDESVICTORY_H_INCLUDED
#define HEARDESVICTORY_H_INCLUDED
 
void defeatDesing();

#endif // HEARDESFUNCS_H_INCLUDED