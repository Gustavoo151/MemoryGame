#include <stdio.h>
#include "raylib.h"


void victoryDesing(){  // Função que mostra o texto da tela de vitoria

    SetWindowTitle("Victory"); 
    ClearBackground(MARROMDARK);
    DrawText("VICTORY", 230, 180, 100, VIOLET);
    DrawText("HOME", 380, 420, 50, WHITE);
    DrawText("EXIT", 380, 480, 50, WHITE);
}


#ifndef HEARDESVICTORY_H_INCLUDED
#define HEARDESVICTORY_H_INCLUDED

void victoryDesing();

#endif // HEARDESFUNCS_H_INCLUDED