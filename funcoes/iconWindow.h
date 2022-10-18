#include <stdio.h>
#include "raylib.h"

//Funçõa para colocar icone na janela
void icon(Image image){
    SetWindowIcon(image);
}

#ifndef HEARDESVICTORY_H_INCLUDED
#define HEARDESVICTORY_H_INCLUDED

void icon(Image image);

#endif // HEARDESFUNCS_H_INCLUDED