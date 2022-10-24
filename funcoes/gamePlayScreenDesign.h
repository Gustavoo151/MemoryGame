#include <stdio.h>
#include "raylib.h"


void gamePlayDesing(){  // função que cria os textos da gamePlay Screen
        
    SetWindowTitle("Memory Game"); // Colocando um nome na janela gamePlay
    
    DrawText("MEMORY GAME", 275, 100, 40, WHITE);
    DrawText("HOME", 780, 360, 35, WHITE);
}


#ifndef HEARDESGAMEPLAYSCREEN_H_INCLUDED
#define HEARDESGAMEPLAYSCREEN_H_INCLUDED
 
void gamePlayDesing();

#endif // HEARDESFUNCS_H_INCLUDED