#include  <stdio.h>
#include "raylib.h"


/*Essa função colocar um nome na janela*/
void setNameWindow(char name[20]){
    SetWindowTitle(name);
}


#ifndef HEARDESSHOWGIF_H_INCLUDED
#define HEARDESSHOWGIF_H_INCLUDED

void setNameWindow(char name[20]);

#endif // HEARDESFUNCS_H_INCLUDED
