#include <stdio.h>
#include "raylib.h"

// Biblioteca de reprodução de Musicas/Sons


void tocarMusica(Music music){
    UpdateMusicStream(music);
    PlayMusicStream(music);
}

#ifndef HEARDESMUSIC_H_INCLUDED
#define HEARDESMUSIC_H_INCLUDED

void tocarMusica(Music music);

#endif // HEARDESFUNCS_H_INCLUDED