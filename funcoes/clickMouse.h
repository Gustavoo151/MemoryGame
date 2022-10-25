#include <stdio.h>
#include "raylib.h"
#include "time.h"

// rectangle click area (int x, int y, int width, int height)
Rectangle botaoRetanguloStart = {350, 275, 160, 50};
Rectangle botaoRetanguloExit = {355, 330, 115, 30};
Rectangle linkGitgub = {680,570, 180, 20}; 
Rectangle backRecords = {360,410, 100, 40};


// // Retangulos para reconhecer área de clique da screen Victory
Rectangle buttonHomeVictory = {380,420,100,50};
Rectangle buttonExitVictory = {380,480,100,50};

Vector2 mousePosition = {0.0f, 0.0f};  // Criando vetor para pegar a posição do mouse

Rectangle buttonExitGamePlay = {780, 360, 85, 35}; // Area de click exitGamePlay
Rectangle buttonSaveGamePlay = {780, 410, 85, 60};


// Retun: Retona o valor da tela que sera aberta apos o click
int clickMouseHomeScreen(){  // Função que faz toda parte defuncionalidade te tela HomeScreen
    
    mousePosition = GetMousePosition(); // Passando a posição do mouse para vetor   
    
    if(CheckCollisionPointRec(mousePosition, botaoRetanguloStart)) // Checando se mouse está em cima do botão
    { 
        DrawText("START", 360, 280, 40, MAGENTA); // Mudando a cor do botão quando mouse está em cima
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))  // Se o botão for clicado retorna o numero da janela a ser aberta
            return 2;
    }   
    if(CheckCollisionPointRec(mousePosition, botaoRetanguloExit))
    {
        DrawText("EXIT", 360, 330, 40, MAGENTA);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return 4;     
    }  
    if(CheckCollisionPointRec(mousePosition, linkGitgub))
    {     
        DrawText("Github repository", 680, 570, 20, MAGENTA);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            OpenURL("https://github.com/Gustavoo151/MemoryGame"); // Abrindo link do gitHub
    }
    return 1; 
}


//Return: Retorna a posicao do numero clicado
int clickGamePlay(){ // Função que faz a mecanica de click no screen gamePlay
   mousePosition = GetMousePosition();
    for(int i =0; i < 16; i++){
        
            if (i < 4){
                Rectangle button = {((i*150) + 115), 180, 140, 85};
               
                if(CheckCollisionPointRec(mousePosition, button) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                        return gamePlay(i);      
            }      
            else if ((i < 8) && (i > 3)){
                Rectangle button = {((i-4)*150 + 115), 280, 140, 85};
                
                if(CheckCollisionPointRec(mousePosition, button) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                        return gamePlay(i); 
            }                      
            else if ((i < 12) && (i > 7)){
                Rectangle button = {((i-8)*150 + 115), 380, 140, 85};
                
                if(CheckCollisionPointRec(mousePosition, button) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    return gamePlay(i); 
            }            
            else if ((i < 16) && (i > 11)){
                Rectangle button = {((i-12)*150 + 115), 480, 140, 85};
                
                if(CheckCollisionPointRec(mousePosition, button) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    return gamePlay(i); 
            }            
            if(CheckCollisionPointRec(mousePosition, buttonExitGamePlay)){ 
                DrawText("HOME", 780, 360, 35, MAGENTA);
                if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    continueGameOpc(2);
                    return 1;
                }
            }             
    }      
    return 2;           
}       


// Return: Retorna True se a opcao save for clicada
int clickSaveGamePlay(){  // Funcao que pega o click do botao save/exit
    mousePosition = GetMousePosition();
    if(CheckCollisionPointRec(mousePosition, buttonSaveGamePlay)){
        DrawText("SAVE", 780, 410, 35, MAGENTA);
        DrawText("EXIT", 780, 440, 35, MAGENTA);
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
            return 1;
    }
}


// Retun: Retona o valor da tela que sera aberta apos o click
int clickVictory(){ // Função que faz toda parte defuncionalidade da tela Victory
    mousePosition = GetMousePosition();
    
    if(CheckCollisionPointRec(mousePosition, buttonHomeVictory)){
        DrawText("HOME", 380, 420, 50, LIGHTGRAY);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return 1;
    }
    else if(CheckCollisionPointRec(mousePosition, buttonExitVictory)){
        DrawText("EXIT", 380, 480, 50, LIGHTGRAY);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            return 4;
    }
    return 3;
}


#ifndef HEARDESCLICKMOUSE_H_INCLUDED
#define HEARDESCLICKMOUSE_H_INCLUDED

int clickSaveGamePlay();
int clickMouseMainScreen();
int clickMouseRecordsScreen();
int clickGamePlay();
int clickVictory();

#endif // HEARDESFUNCS_H_INCLUDED