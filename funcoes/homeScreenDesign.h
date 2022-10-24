#include <stdio.h>
#include "raylib.h"


// @param : recebe o tipo da fonte que ira ser usada nos textos de menu 
void menuDesign(Font fontType){  // Desing da home
      
    SetWindowTitle("Memory Game");  // Colocando um nome na janela main
    
    DrawTextEx(fontType, "Memory Game", (Vector2){220,180}, 80, 5, WHITE);
    DrawText("START", 360, 280, 40, WHITE);
    DrawText("EXIT", 360, 330, 40, WHITE);
    DrawText("©Gustavo Oliveira", 20, 570, 20, WHITE);
    DrawText("Github repository", 680, 570, 20, WHITE);
}

#ifndef HEARDESMEUNDESIGN_H_INCLUDED
#define HEARDESMEUNDESIGN_H_INCLUDED

void menuDesing(Font fontType);

#endif // HEARDESFUNCS_H_INCLUDED