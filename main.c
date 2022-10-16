#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#include "funcoes/musicPlayer.h"  // Reproduz arquivos de som
#include "funcoes/records.h" // Desing e a mecanica da janela records
#include "funcoes/victoryDesing.h" // Desing e a mecanica da janela Victory
#include "funcoes/mainScreen.h" // Desing e a mecanica da janela principal
#include "funcoes/defeatScreen.h" // Desing e a mecanica da janela derrota
#include "funcoes/clickMouse.h" // Pegar o click do mouse
#include "funcoes/nameWindow.h" // Coloca um nome na janela
#include "funcoes/gamePlayScreen.h" // Biblioteca que contém o desing da tela de gamePlay
#include "funcoes/urlOpen.h" // Biblioteca que abre um URL


//#include "funcoes/incoWindow.h" // Essa função colocar um icone na janela
//#include "funcoes/showGif.h" // Essa biblioteca contém o desing e a mecanica da janela derrota


int main(){
   const int screenWidth = 900;  // Largura de tela 
   const int screenHeight = 620; // Altura da tela
   
   InitWindow(screenWidth, screenHeight, "Jogo da menoria");  // Inicializa a tela
    
   SetTargetFPS(60);  // Define a quantidade de FPS do jogo
  
   InitAudioDevice(); 

   char nameMusicHome[40] = "media/Music/MusicHome.mp3";
   char nameMusicGamePlay[40] = "media/Music/MusicGamePlay.mp3";
   char nameMusicDefeat[40] = "media/Music/MusicDefeat.mp3";
   
   // Arquivo tipoMusic para tocarMusica
    Music musicHome = LoadMusicStream(nameMusicHome);
    Music musicGameP = LoadMusicStream(nameMusicGamePlay);
    Music musicDefeat = LoadMusicStream(nameMusicDefeat);  

    Texture2D homeBackGround = LoadTexture("media/imagens/FundoMain.png"); // BackGroundHome
    Texture2D backGroundRecords = LoadTexture("media/imagens/BackGroundRecords.png"); // BackGroundRecords
    Texture2D backGroundGame = LoadTexture("media/imagens/BackGroundGamePlay.png"); // BackGroundGamePlay
    Texture2D backGroundVictor = LoadTexture("media/imagens/BackGroundVictory.png"); // BackGroundVirctory
    
   int opcTela = 1;  // Variavel para Trocar de tela
   
   while(!WindowShouldClose())  // Deixa tela aberta até os esc ser pressionado
   {
       
        BeginDrawing();  // Tela de configuração (framebuffer) para começar a desenhar
        
        switch (opcTela)
        {
            case 1:
            {
                DrawTextureEx(homeBackGround, (Vector2){0, 0}, 0, 0.70f, WHITE); // Desenhando o fundo da tela main
                menuDesing();
                opcTela = clickMouseMainScreen(); // Função que mostra
                tocarMusica(musicHome); // função reproduz a música
                break;   
            }
            case 2:
            {
                DrawTextureEx(backGroundGame, (Vector2){0, 0}, 0, 0.345f, WHITE); // Desenhando a textura da imagem 
                gamePlayDesing();
                tocarMusica(musicGameP); // função reproduz a música
                break;
            }
            case 3:
            {
                DrawTextureEx(backGroundRecords, (Vector2){0, 0}, 0, 1.0f, WHITE); // Desenhando a textura da imagem
                recordsScreen();  // Desinig dos recordes
                opcTela = clickMouseRecordsScreen(); // Passanto o valor da screen a ser aberta
                tocarMusica(musicHome); // função reproduz a música
                break;
            }
            case 4:
            {
                DrawTextureEx(backGroundVictor, (Vector2){0, 0}, 0, 0.49f, WHITE); // Desenhando a textura da imagem
                victoryDesing();
               // tocarMusica(musica); // função reproduz a música
                break;
            }
            case 5:
            {
                defeatDesing();  
                tocarMusica(musicDefeat); // função reproduz a música
                break;
            }	
            case 6:
            {
                 return NULL; // Saindo do jogo
            }

        }
        
        EndDrawing(); // Finalize o desenho da tela e troque os buffers (buffer duplo)
    }
    
  
    UnloadMusicStream(musicHome);  // descarregar fluxo de música
    UnloadMusicStream(musicGameP);
    UnloadMusicStream(musicDefeat);
    
    UnloadTexture(homeBackGround);  // Unload background texture
    UnloadTexture(backGroundRecords);  
    UnloadTexture(backGroundGame);  
    
    
    CloseAudioDevice();
   
    CloseWindow(); // Fechar janela e contexto OpenGL
    
    return 0;
}