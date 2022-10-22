#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#include "funcoes/musicPlayer.h"  // Reproduz arquivos de som
#include "funcoes/victoryDesing.h" // Desing e a mecanica da janela Victory
#include "funcoes/mainScreen.h" // Desing e a mecanica da janela principal
#include "funcoes/clickMouse.h" // Pegar o click do mouse
#include "funcoes/nameWindow.h" // Coloca um nome na janela
#include "funcoes/gamePlayScreen.h" // Biblioteca que contém o desing da tela de gamePlay
#include "funcoes/urlOpen.h" // Biblioteca que abre um URL
#include "funcoes/iconWindow.h" // Biblioteca que adicona o icone na janela
#include "funcoes/gamePlayMecanics.h" // Biblioteca com toda a parte de gamePlay do jogo


int main(){
   const int screenWidth = 900;  // Largura de tela 
   const int screenHeight = 620; // Altura da tela
   
    InitWindow(screenWidth, screenHeight, "Jogo da menoria");  // Inicializa a tela
    
    SetTargetFPS(60);  // Define a quantidade de FPS do jogo
  
    InitAudioDevice(); 
   
    Music musicHome = LoadMusicStream("media/Music/MusicHome.mp3"); // Arquivo tipoMusic para tocarMusica
    Music musicGameP = LoadMusicStream("media/Music/MusicGamePlay.mp3");

    Texture2D homeBackGround = LoadTexture("media/imagens/FundoMain.png"); // BackGroundHome
    Texture2D backGroundRecords = LoadTexture("media/imagens/BackGroundRecords.png"); // BackGroundRecords
    Texture2D backGroundGame = LoadTexture("media/imagens/BackGroundGamePlay.png"); // BackGroundGamePlay
    Texture2D backGroundVictor = LoadTexture("media/imagens/BackGroundVictory.png"); // BackGroundVirctory
                
                
    Image imagemTeste = LoadImage("media/imagens/iconBrain.png");
    
    int opcTela = 1;  // Variavel para Trocar de tela
    
   while(!WindowShouldClose())  // Deixa tela aberta até os esc ser pressionado
   {
        BeginDrawing();  // Tela de configuração (framebuffer) para começar a desenhar
        
        icon(imagemTeste); // Colocando icone da janela
        
        
        switch (opcTela)
        {
            case 1:
            {
                DrawTextureEx(homeBackGround, (Vector2){0, 0}, 0, 0.70f, WHITE); // Desenhando o fundo da tela main
                resetAndStartsGameMecanics();
                menuDesing();
                opcTela = clickMouseMainScreen(); // Função que mostra
                tocarMusica(musicHome); // função reproduz a música
                break;   
            }
            case 2:
            {
                DrawTextureEx(backGroundGame, (Vector2){0, 0}, 0, 0.345f, WHITE); // Desenhando a textura da imagem                          
                gamePlayDesing();
                
                opcTela = clickGamePlay();
               
                showCards();
                
                checkCards();
                tocarMusica(musicGameP); // função reproduz a música
                //opcTela = clickExitGamePlay();
                break;
            }
            case 3:
            {
                DrawTextureEx(backGroundVictor, (Vector2){0, 0}, 0, 0.49f, WHITE); // Desenhando a textura da imagem
                victoryDesing();
               // tocarMusica(musica); // função reproduz a música
                break;
            }
            case 5:
            {
                 return NULL; // Saindo do jogo
            }
        }
        
        EndDrawing(); // Finalize o desenho da tela e troque os buffers (buffer duplo)
    }
  
    UnloadMusicStream(musicHome);  // descarregar fluxo de música
    UnloadMusicStream(musicGameP);
    
    UnloadTexture(homeBackGround);  // Unload background texture
    UnloadTexture(backGroundRecords);  
    UnloadTexture(backGroundGame);  
     
    CloseAudioDevice();
   
    CloseWindow(); // Fechar janela e contexto OpenGL
    
    return 0;
}