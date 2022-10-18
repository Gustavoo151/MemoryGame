#include <stdio.h>
#include "raylib.h"
#include <time.h>

int pair[16] = {1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};


void shuffleVector(int *vet, int vetSize){  // Embaralhando vetor
    srand(time(NULL));
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