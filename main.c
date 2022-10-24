#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#include "funcoes/musicPlayer.h"  // Reproduz arquivos de som
#include "funcoes/victoryDesing.h" // Desing e a mecanica da janela Victory
#include "funcoes/homeScreenDesign.h" // Desing e a mecanica da janela principal
#include "funcoes/clickMouse.h" // Pegar o click do mouse
#include "funcoes/gamePlayMecanics.h" // Biblioteca com toda a parte de gamePlay do jogo
#include "funcoes/gamePlayScreenDesign.h" // Biblioteca que contém o desing da tela de gamePlay


int main(){
   const int screenWidth = 900;  // Largura de tela 
   const int screenHeight = 620; // Altura da tela
   
    InitWindow(screenWidth, screenHeight, "Jogo da menoria");  // Inicializa a tela
    
    SetTargetFPS(60);  // Define a quantidade de FPS do jogo
  
    InitAudioDevice(); 
   
    Music musicHome = LoadMusicStream("media/Music/MusicHome.mp3"); // Arquivo tipoMusic para tocarMusica
    Music musicGameP = LoadMusicStream("media/Music/MusicGamePlay.mp3");
    Music musicVictory = LoadMusicStream("media/Music/MusicVictory.mp3");

    Texture2D homeBackGround = LoadTexture("media/imagens/FundoMain.png"); // BackGroundHome
    Texture2D backGroundGame = LoadTexture("media/imagens/BackGroundGamePlay.png"); // BackGroundGamePlay
    Texture2D backGroundVictory = LoadTexture("media/imagens/BackGroundVictory.png"); // BackGroundVirctory
                
    Image IconImage = LoadImage("media/imagens/iconBrain.png");
    SetWindowIcon(IconImage);
    
    Font fonteMain = LoadFont("fonts/Symtext.ttf"); // Carragando fonte da função main

    
    int opcTela = 1;  // Variavel para Trocar de tela
    
   while(!WindowShouldClose())  // Deixa tela aberta até os esc ser pressionado
   {
        BeginDrawing();  // Tela de configuração (framebuffer) para começar a desenhar           
        
        switch (opcTela)
        {
            case 1:
            {
                
                DrawTextureEx(homeBackGround, (Vector2){0, 0}, 0, 0.70f, WHITE); // Desenhando o fundo da tela main
                resetAndStartsGameMecanics();
                menuDesign(fonteMain);
                opcTela = clickMouseMainScreen(); // Função que mostra
                playMusic(musicHome); // função reproduz a música
                break;   
            }
            case 2:
            {
                DrawTextureEx(backGroundGame, (Vector2){0, 0}, 0, 0.345f, WHITE); // Desenhando a textura da imagem                          
                gamePlayDesing();                
                opcTela = clickGamePlay();
                showCards();  
                checkCards();
                playMusic(musicGameP); // função reproduz a música
                break;
            }
            case 3:
            {
                DrawTextureEx(backGroundVictory, (Vector2){0, 0}, 0, 0.49f, WHITE); // Desenhando a textura da imagem
                victoryDesing();
                playMusic(musicVictory); // função reproduz a música
                opcTela = clickVictory();
                break;
            }
            case 4:
            {
                 return 0; // Saindo do jogo
            }
        }
        
        EndDrawing(); // Finalize o desenho da tela e troque os buffers (buffer duplo)
    }
  
    UnloadMusicStream(musicHome);  // descarregar fluxo de música
    UnloadMusicStream(musicGameP);
    UnloadMusicStream(musicVictory);
    
    UnloadTexture(homeBackGround);  // Unload background texture
    UnloadTexture(backGroundVictory);  
    UnloadTexture(backGroundGame);  
     
    CloseAudioDevice();
   
    CloseWindow(); // Fechar janela e contexto OpenGL
    
    return 0;
}
