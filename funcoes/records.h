#include <stdio.h>
#include "raylib.h"

void recordsDesing(){  // Função para mostra os recordes desing
    ClearBackground(MARROMDARK);
    
    char nameWindowRecords[20] = "RECORDS";
    /*
        Depois fazer um for para colocar printar os tres lugares (so quando a funcao records estiver pronta)
    */
    DrawRectangleGradientV (00, 00, 900, 540, WHITE, MARROMDARK);  // fazendo um efeito grandiente no plano de fundo
    char lugarUm[10] = "1º : 35";
    char lugarDois[10] = "2º: 52";
    char lugarTres[10] = "3º: 65";
    
    setNameWindow(nameWindowRecords); // Colocando um nome na janela records
    
    DrawText("RECORDS", 310, 140, 60, WHITE);
    DrawText(lugarUm, 360,230, 40, WHITE);
    DrawText(lugarDois, 360,270, 40, WHITE);
    DrawText(lugarTres, 360,310, 40, WHITE);
    DrawText("BACK", 360,410, 40, WHITE);
}


#ifndef HEARDESSHOWGIF_H_INCLUDED
#define HEARDESSHOWGIF_H_INCLUDED

void recordsDesing();

#endif // HEARDESFUNCS_H_INCLUDED
