#include <stdio.h>
#include "raylib.h"

//int clickMouse(int x, int y, int width, int height)
int clickMouseMainScreen(){
    
    // 350, 350, 100, 100 Tamanho da botão
    // 350,275, 165, 50 botão retangulo
    Rectangle botaoRetanguloStart = {350, 275, 160, 50}; // Criando um retangulo para o start
    Rectangle botaoRetanguloRescords = {357, 330, 195, 30}; // Criando um retangulo para o start
    Rectangle botaoRetanguloExit = {355, 380, 115, 30}; // Criando um retangulo para o exit
    Rectangle linkGitgub = {680,600, 180, 20}; // Ratangulo de acesso URL gitHub
    
    
    Vector2 mousePosition = {0.0f, 0.0f};  // Criando vetor para pegar a posição do mouse
    
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
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            return 1;
           // CloseWindow();
        }       
    }
    if(CheckCollisionPointRec(mousePosition, linkGitgub))
    {     
        DrawText("Github repository", 680, 600, 20, WHITE);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            urlOpen(); // Abrindo link do gitHub
    }

    return 1; 
}

#ifndef HEARDESVICTORY_H_INCLUDED
#define HEARDESVICTORY_H_INCLUDED

int clickMouseMainScreen();

#endif // HEARDESFUNCS_H_INCLUDED