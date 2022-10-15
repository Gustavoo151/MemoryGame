#include <stdio.h>
#include "raylib.h"

//Funçõa para colocar icone na janela
void icon(){
        Image iconImage = LoadImageAnim("media/imagens/brainstorm.png");
        SetWindowIcon(iconImage);
}

#ifndef HEARDESVICTORY_H_INCLUDED
#define HEARDESVICTORY_H_INCLUDED

void icon();

#endif // HEARDESFUNCS_H_INCLUDED