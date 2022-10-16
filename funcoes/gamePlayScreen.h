#include <stdio.h>
#include "raylib.h"



void gamePlayDesing(){
    
    ClearBackground(MARROMDARK);
    
    char nameWindowGamePlay[20] = "Memory Game";
    setNameWindow(nameWindowGamePlay); // Colocando um nome na janela gamePlay
    
    DrawText("GAME PLAY", 300, 180, 40, WHITE);
        
}


#ifndef HEARDESGAMEPLAY_H_INCLUDED
#define HEARDESGAMEPLAY_H_INCLUDED
 
void gamePlayDesing();

#endif // HEARDESFUNCS_H_INCLUDED