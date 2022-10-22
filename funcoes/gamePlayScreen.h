#include <stdio.h>
#include "raylib.h"


void gamePlayDesing(){
        
    char nameWindowGamePlay[20] = "Memory Game";
    setNameWindow(nameWindowGamePlay); // Colocando um nome na janela gamePlay
    
    DrawText("MEMORY GAME", 275, 100, 40, WHITE);
    DrawText("HOME", 780, 360, 35, WHITE);
}


#ifndef HEARDESGAMEPLAY_H_INCLUDED
#define HEARDESGAMEPLAY_H_INCLUDED
 
void gamePlayDesing();

#endif // HEARDESFUNCS_H_INCLUDED