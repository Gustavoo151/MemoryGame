#include <stdio.h>
#include "raylib.h"

Music musicPlay(){ // Função que carraga arquivo de musica
    InitAudioDevice();    
    Music music = LoadMusicStream("media/Music/MusicaFundo-2.mp3");
    return music;
}

void tocarMusica(Music music){
    UpdateMusicStream(music);
    PlayMusicStream(music);
}

#ifndef HEARDESMUSIC_H_INCLUDED
#define HEARDESMUSIC_H_INCLUDED

void tocarMusica(Music music);
Music musicPlay();

#endif // HEARDESFUNCS_H_INCLUDED