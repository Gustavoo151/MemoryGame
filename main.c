#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#include "funcoes/musicPlayer.h"  // Biblioteca para reproduzir arquivos de som
#include "funcoes/records.h" // Biblioteca que contém o desing e a mecanica da janela records
#include "funcoes/victoryDesing.h" // Biblioteca que contém o desing e a mecanica da janela Victory
#include "funcoes/mainScreen.h" // Biblioteca que contém o desing e a mecanica da janela principal
#include "funcoes/defeatScreen.h" // Essa biblioteca contém o desing e a mecanica da janela derrota
#include "funcoes/clickMouse.h" // Essa função pegar o click do mouse
#include "funcoes/nameWindow.h" // Essa função colocar um nome na janela
#include "funcoes/gamePlayScreen.h" // Bibioteca que contém o desing da tela de gamePlay
#include "funcoes/urlOpen.h" // Bibioteca que abre um URL



//#include "funcoes/incoWindow.h" // Essa função colocar um icone na janela
//#include "funcoes/showGif.h" // Essa biblioteca contém o desing e a mecanica da janela derrota


int main(){
   const int screenWidth = 900;  // Largura de tela 
   const int screenHeight = 650; // Altura da tela
   
   InitWindow(screenWidth, screenHeight, "Jogo da menoria");  // Inicializa a tela
    
   SetTargetFPS(60);  // Define a quantidade de FPS do jogo
   
   Music musica = musicPlay(); // Passando o arquivo Music para variável musica
 
   int opcTela = 1  ;  // Variavel para Trocar de tela
   
   //icon();

   
   while(!WindowShouldClose())  // Deixa tela aberta até os esc ser pressionado
       {
           // Lugar onde posso colocar as funçoes
        
        
        //---------------------------------------------

        
        BeginDrawing();  // Tela de configuração (framebuffer) para começar a desenhar
        
        if (opcTela == 1)
        {   
            menuDesing();
            opcTela = clickMouseMainScreen(); // Função que mostra
            tocarMusica(musica); // função reproduz a música
        } 
        
        else if (opcTela == 2)
        {
            gamePlayDesing();
            tocarMusica(musica); // função reproduz a música
        }
               
        else if (opcTela == 3)
        {
            recordsDesing();  // Desinig dos recordes
            tocarMusica(musica); // função reproduz a música
            
        }
        
        else if(opcTela == 5)
        {
            victoryDesing();
            tocarMusica(musica); // função reproduz a música
        }
        
        else if(opcTela == 4)
        {
            defeatDesing();  
            tocarMusica(musica); // função reproduz a música
        }
        
        
        EndDrawing(); // Finalize o desenho da tela e troque os buffers (buffer duplo)
    }
   // funcao fechar musuc
    UnloadMusicStream(musica);
    CloseAudioDevice();
   
    CloseWindow(); // Fechar janela e contexto OpenGL
    
    return 0;
}