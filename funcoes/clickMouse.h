#include <stdio.h>
#include "raylib.h"
#include "time.h"

// rectangle click area (int x, int y, int width, int height)
Rectangle botaoRetanguloStart = {350, 275, 160, 50};
Rectangle botaoRetanguloExit = {355, 330, 115, 30};
Rectangle linkGitgub = {680,570, 180, 20}; 
Rectangle backRecords = {360,410, 100, 40};

// Retangulos para reconhecer área de clique da screen gamePlay
Rectangle button1 = {115, 180, 140, 85};
Rectangle button2 = {272, 180, 140, 85};
Rectangle button3 = {430, 180, 140, 85};
Rectangle button4 = {585, 180, 140, 85};
Rectangle button5 = {115, 280, 140, 85};
Rectangle button6 = {272, 280, 140, 85};
Rectangle button7 = {430, 280, 140, 85};
Rectangle button8 = {585, 280, 140, 85};
Rectangle button9 = {115, 380, 140, 85};   
Rectangle button10 = {272, 380, 140, 85}; 
Rectangle button11 = {430, 380, 140, 85};
Rectangle button12 = {585, 380, 140, 85};
Rectangle button13 = {115, 480, 140, 85};
Rectangle button14 = {272, 480, 140, 85};
Rectangle button15 = {430, 480, 140, 85};
Rectangle button16 = {585, 480, 140, 85};

Vector2 mousePosition = {0.0f, 0.0f};  // Criando vetor para pegar a posição do mouse

Rectangle buttonExitGamePlay = {780, 360, 85, 35}; // Area de click exitGamePlay

int clickMouseMainScreen(){
    
    mousePosition = GetMousePosition(); // Passando a posição do mouse para vetor   
    
    if(CheckCollisionPointRec(mousePosition, botaoRetanguloStart)) // Checando se mouse está em cima do botão
    { 
        DrawText("START", 360, 280, 40, MAGENTA); // Mudando cor do botão quando mouse está em cima
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))  // Se o botão for clicado retorna o numero da janela a ser aberta
            return 2;
    }   
    if(CheckCollisionPointRec(mousePosition, botaoRetanguloExit))
    {
        DrawText("EXIT", 360, 330, 40, MAGENTA);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return 5;     
    }  
    if(CheckCollisionPointRec(mousePosition, linkGitgub))
    {     
        DrawText("Github repository", 680, 570, 20, MAGENTA);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            urlOpen(); // Abrindo link do gitHub
    }
    return 1; 
}


int clickGamePlay(){  // Função a posição do botão clicado 
    
    mousePosition = GetMousePosition();  
    int screenRedirect;
    
    if(CheckCollisionPointRec(mousePosition, button1) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){  // Checando click do mouse
        screenRedirect = gamePlay(0);
        return screenRedirect;
    } 
    else if(CheckCollisionPointRec(mousePosition, button2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){ 
        screenRedirect = gamePlay(1);
        return screenRedirect;
    }     
    else if(CheckCollisionPointRec(mousePosition, button3) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){ 
        screenRedirect = gamePlay(2);
        return screenRedirect;
    }     
    else if(CheckCollisionPointRec(mousePosition, button4) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){ 
        screenRedirect = gamePlay(3);
        return screenRedirect;
    }     
    else if(CheckCollisionPointRec(mousePosition, button5) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){  
        screenRedirect = gamePlay(4);
        return screenRedirect;
    }            
    else if(CheckCollisionPointRec(mousePosition, button6) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){ 
        screenRedirect = gamePlay(5);
        return screenRedirect;
    }         
    else if(CheckCollisionPointRec(mousePosition, button7) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){ 
        screenRedirect = gamePlay(6);
        return screenRedirect;
    }     
    else if(CheckCollisionPointRec(mousePosition, button8) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){ 
        screenRedirect = gamePlay(7);
        return screenRedirect;
    }     
    else if(CheckCollisionPointRec(mousePosition, button9) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){ 
        screenRedirect = gamePlay(8);
        return screenRedirect;
    }     
    else if(CheckCollisionPointRec(mousePosition, button10) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){ 
        screenRedirect = gamePlay(9);
        return screenRedirect;
    }     
    else if(CheckCollisionPointRec(mousePosition, button11) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){ 
        screenRedirect = gamePlay(10);
        return screenRedirect;
    }     
    else if(CheckCollisionPointRec(mousePosition, button12) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){ 
        screenRedirect = gamePlay(11);
        return screenRedirect;
    }    
    else if(CheckCollisionPointRec(mousePosition, button13) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){ 
        screenRedirect = gamePlay(12);
        return screenRedirect;
    }         
    else if(CheckCollisionPointRec(mousePosition, button14) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){ 
        screenRedirect = gamePlay(13);
        return screenRedirect;
    }     
    else if(CheckCollisionPointRec(mousePosition, button15) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
        screenRedirect = gamePlay(14);
        return screenRedirect;
    }     
    else if(CheckCollisionPointRec(mousePosition, button16) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
        screenRedirect = gamePlay(15);
        return screenRedirect;
    }
    return 2;
}


int clickExitGamePlay(){ // Função que leva do gamePlay para tela inicial
    if(CheckCollisionPointRec(mousePosition, buttonExitGamePlay))
    { 
        DrawText("EXIT", 780, 360, 35, MAGENTA);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return 1;
    }
    return 2;
}

#ifndef HEARDESVICTORY_H_INCLUDED
#define HEARDESVICTORY_H_INCLUDED

int clickMouseMainScreen();
int clickMouseRecordsScreen();
int clickGamePlay();
int clickExitGamePlay();

#endif // HEARDESFUNCS_H_INCLUDED