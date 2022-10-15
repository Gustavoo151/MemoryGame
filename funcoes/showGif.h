#include <stdio.h>
#include "raylib.h"


#define MAX_FRAME_DELAY     20
#define MIN_FRAME_DELAY      1


void aninGif(){ // Antes do while


    int animFrames = 0;
    
    Image imScarfyAnim = LoadImageAnim("media/imagens/trofel.gif", &animFrames);
    Texture2D texScarfyAnim = LoadTextureFromImage(imScarfyAnim);
    
    unsigned int nextFrameDataOffset = 0;  // Current byte offset to next frame in image.data
    
    int currentAnimFrame = 0;       // Current animation frame to load and draw
    int frameDelay = 8;             // Frame delay to switch between animation frames
    int frameCounter = 0;           // General frames counter
}

void gifDentro(){
    frameCounter++;
    
    if (frameCounter >= frameDelay)
        {
            currentAnimFrame++;
            if (currentAnimFrame >= animFrames) 
                currentAnimFrame = 0;

            nextFrameDataOffset = imScarfyAnim.width*imScarfyAnim.height*4*currentAnimFrame;

            UpdateTexture(texScarfyAnim, ((unsigned char *)imScarfyAnim.data) + nextFrameDataOffset);

            frameCounter = 0;
            
            DrawTexture(texScarfyAnim, GetScreenWidth()/2 - texScarfyAnim.width/2, 140, WHITE);
        }
}

void fimGif(){
    UnloadTexture(texScarfyAnim);   // Unload texture
    UnloadImage(imScarfyAnim);
    
}


#ifndef HEARDESSHOWGIF_H_INCLUDED
#define HEARDESSHOWGIF_H_INCLUDED

void mostra(int a);
void mostra2();

#endif // HEARDESFUNCS_H_INCLUDED
