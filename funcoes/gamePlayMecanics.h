#include <stdio.h>
#include "raylib.h"


void shuffleVector(int *vet, int vetSize){
    for (int i = 1; i < vetSize; i++)
    {
        int r = rand() % vetSize;

        int temp = vet[i];
        vet[i] = vet[r];
        vet[r] = temp;
    }
}

#ifndef HEARDESGAMEPLAY_H_INCLUDED
#define HEARDESGAMEPLAY_H_INCLUDED
 
void shuffleVector(int *vet, int vetSize);

#endif // HEARDESFUNCS_H_INCLUDED