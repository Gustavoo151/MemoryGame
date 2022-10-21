#include <stdio.h>
#include "raylib.h"


void menuDesing(){  // Desing da home
    
    char nameWindowMain[20] = "Memory Game";
    
    setNameWindow(nameWindowMain); // Colocando um nome na janela main

    DrawText("MEMORY GAME", 280, 180, 50, WHITE);
    DrawText("START", 360, 280, 40, WHITE);
    DrawText("EXIT", 360, 330, 40, WHITE);
    DrawText("©Gustavo Oliveira", 20, 570, 20, WHITE);
    DrawText("Github repository", 680, 570, 20, WHITE);
}

#ifndef HEARDESVICTORY_H_INCLUDED
#define HEARDESVICTORY_H_INCLUDED

void menuDesing();

#endif // HEARDESFUNCS_H_INCLUDED