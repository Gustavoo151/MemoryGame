#include <stdio.h>
#include "raylib.h"

// rectangle click area (int x, int y, int width, int height)
Rectangle botaoRetanguloStart = {350, 275, 160, 50};
Rectangle botaoRetanguloRescords = {357, 330, 195, 30};
Rectangle botaoRetanguloExit = {355, 380, 115, 30};
Rectangle linkGitgub = {680,600, 180, 20}; 
Rectangle backRecords = {360,410, 100, 40};


Vector2 mousePosition = {0.0f, 0.0f};  // Criando vetor para pegar a posição do mouse

int clickMouseMainScreen(){
    
    mousePosition = GetMousePosition(); // Passando a posição do mouse para vetor   
    
    if(CheckCollisionPointRec(mousePosition, botaoRetanguloStart)) // Checando se mouse está em cima do botão
    { 
        DrawText("START", 360, 280, 40, BLACK); // Mudando cor do botão quando mouse está em cima
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))  // Se o botão for clicado retorna o numero da janela a ser aberta
            return 2;
    } 
    
    if(CheckCollisionPointRec(mousePosition, botaoRetanguloRescords))
    { 
        DrawText("RECORDS", 360, 330, 40, BLACK); 
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return 3; // Retornando qual tela entrar
    }
    
    if(CheckCollisionPointRec(mousePosition, botaoRetanguloExit))
    {
        DrawText("EXIT", 360, 380, 40, BLACK);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return 6;     
    }
    
    if(CheckCollisionPointRec(mousePosition, linkGitgub))
    {     
        DrawText("Github repository", 680, 600, 20, WHITE);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            urlOpen(); // Abrindo link do gitHub
    }
    
    return 1; 
}

int clickMouseRecordsScreen(){
    
    mousePosition = GetMousePosition(); // Passando a posição do mouse para vetor 
    
    if(CheckCollisionPointRec(mousePosition, backRecords))
    {
        DrawText("BACK", 360,410, 40, BLACK);
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return 1;
    }
    
    return 3;
    
}

#ifndef HEARDESVICTORY_H_INCLUDED
#define HEARDESVICTORY_H_INCLUDED

int clickMouseMainScreen();
int clickMouseRecordsScreen();

#endif // HEARDESFUNCS_H_INCLUDED