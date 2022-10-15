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
   const int screenHeight = 650; // Altura da tela
   
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

   int opcTela = 1;  // Variavel para Trocar de tela
   
   while(!WindowShouldClose())  // Deixa tela aberta até os esc ser pressionado
   {
       
        BeginDrawing();  // Tela de configuração (framebuffer) para começar a desenhar
        
        switch (opcTela)
        {
            case 1:
            {
                menuDesing();
                opcTela = clickMouseMainScreen(); // Função que mostra
                tocarMusica(musicHome); // função reproduz a música
                break;   
            }
            case 2:
            {
                gamePlayDesing();
                tocarMusica(musicGameP); // função reproduz a música
                break;
            }
            case 3:
            {
                recordsDesing();  // Desinig dos recordes
                opcTela = clickMouseRecordsScreen(); // Passanto o valor da screen a ser aberta
                tocarMusica(musicHome); // função reproduz a música
                break;
            }
            case 4:
            {
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
    
    CloseAudioDevice();
   
    CloseWindow(); // Fechar janela e contexto OpenGL
    
    return 0;
}