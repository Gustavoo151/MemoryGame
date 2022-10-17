#include <stdio.h>
#include "raylib.h"

// rectangle click area (int x, int y, int width, int height)
Rectangle botaoRetanguloStart = {350, 275, 160, 50};
Rectangle botaoRetanguloRescords = {357, 330, 195, 30};
Rectangle botaoRetanguloExit = {355, 380, 115, 30};
Rectangle linkGitgub = {680,570, 180, 20}; 
Rectangle backRecords = {360,410, 100, 40};


Vector2 mousePosition = {0.0f, 0.0f};  // Criando vetor para pegar a posição do mouse

int clickMouseMainScreen(){
    
    mousePosition = GetMousePosition(); // Passando a posição do mouse para vetor   
    
    if(CheckCollisionPointRec(mousePosition, botaoRetanguloStart)) // Checando se mouse está em cima do botão
    { 
        DrawText("START", 360, 280, 40, MAGENTA); // Mudando cor do botão quando mouse está em cima
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))  // Se o botão for clicado retorna o numero da janela a ser aberta
            return 2;
    } 
    
    if(CheckCollisionPointRec(mousePosition, botaoRetanguloRescords))
    { 
        DrawText("RECORDS", 360, 330, 40, MAGENTA); 
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return 3; // Retornando qual tela entrar
    }
    
    if(CheckCollisionPointRec(mousePosition, botaoRetanguloExit))
    {
        DrawText("EXIT", 360, 380, 40, MAGENTA);
        
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


int clickMouseRecordsScreen(){ // Função que pegar o click e redireciona para janela escolhida na RecordsScreen
    
    mousePosition = GetMousePosition(); // Passando a posição do mouse para vetor 
    
    if(CheckCollisionPointRec(mousePosition, backRecords))
    {
        DrawText("BACK", 360,410, 40, BLACK);
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return 1;
    }
    
    return 3;
    
}

// Retangulos para recpnhecer área de clique da screen gamePlay
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


int clickGamePlay(){  // Função a posição do botão clicado 
    
    mousePosition = GetMousePosition();  
    
    if(CheckCollisionPointRec(mousePosition, button1)) // Checando se mouse está em cima do botão
    { 
        DrawText("1", 155, 200, 40, BLACK);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))  // Verficando se o botão foi clicado
            return 2; // Retorna numero do botão clicado
    } 
    
    if(CheckCollisionPointRec(mousePosition, button2))
    { 
        DrawText("2", 300, 200, 40, BLACK);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
            return 2;
    } 
    
    if(CheckCollisionPointRec(mousePosition, button3))
    { 
        DrawText("3", 450, 200, 40, BLACK);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
            return 3;
    } 
    
    if(CheckCollisionPointRec(mousePosition, button4))
    { 
        DrawText("4", 600, 200, 40, BLACK);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return 4;
    } 
    
    if(CheckCollisionPointRec(mousePosition, button5)) 
    { 
        DrawText("5", 155, 300, 40, BLACK); 
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
            return 5;
    }         
    
    if(CheckCollisionPointRec(mousePosition, button6)) 
    { 
        DrawText("6", 300, 300, 40, BLACK); 
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
            return 6;
    }     
    
    if(CheckCollisionPointRec(mousePosition, button7))
    { 
        DrawText("7", 450, 300, 40, BLACK);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))  
            return 7;
    } 
    
    if(CheckCollisionPointRec(mousePosition, button8))
    { 
        DrawText("8", 600, 300, 40, BLACK);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))  
            return 8;
    } 
    
    if(CheckCollisionPointRec(mousePosition, button9))
    { 
        DrawText("9", 155, 400, 40, BLACK);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))  
            return 9;
    }  
    
    if(CheckCollisionPointRec(mousePosition, button10))
    { 
        DrawText("10", 300, 400, 40, BLACK);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))  
            return 10;
    } 
    
    if(CheckCollisionPointRec(mousePosition, button11))
    { 
        DrawText("11", 450, 400, 40, BLACK);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))  
            return 11;
    } 
    
    if(CheckCollisionPointRec(mousePosition, button12))
    { 
        DrawText("12", 600, 400, 40, BLACK);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return 12;
    } 
    
    if(CheckCollisionPointRec(mousePosition, button13))
    { 
        DrawText("13", 155, 500, 40, BLACK);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return 13;
    } 
        
    if(CheckCollisionPointRec(mousePosition, button14))
    { 
        DrawText("14", 300, 500, 40, BLACK);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
            return 14;
    } 
    
    if(CheckCollisionPointRec(mousePosition, button15))
    { 
        DrawText("15", 450, 500, 40, BLACK);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return 15;
    } 
    
    if(CheckCollisionPointRec(mousePosition, button16))
    { 
        DrawText("16", 600, 500, 40, BLACK);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))     
            return 16;
    }     
    
    return 0;
}

Rectangle buttonExitGamePlay = {780, 360, 85, 35};

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