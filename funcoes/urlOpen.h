#include <stdio.h>
#include "raylib.h"

char link[100] = "https://github.com/Gustavoo151/MemoryGame";  // Link do repositório de GitHub

void urlOpen(){
    
    OpenURL(link);                             
}

#ifndef HEARDESURLOPEN_H_INCLUDED
#define HEARDESURLOPEN_H_INCLUDED
 
void urlOpen();

#endif // HEARDESFUNCS_H_INCLUDED