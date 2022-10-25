 #include <stdio.h>
 
 
void saveGameProgress(int cards[16], int cardsAux[16]){  // Funcao que salva em dois arquivos os dados dos vetores cards e cardsAux
    FILE *saveArchiveCards;
    FILE *saveArchiveCardsAux;
    
    saveArchiveCards = fopen("saveGameData/saveDadosCards.txt", "w+");
    saveArchiveCardsAux = fopen("saveGameData/saveDadosCardsAux.txt", "w+");
    
    if(saveArchiveCards != NULL){
        for(int i = 0; i< 16; i++)           
            fprintf(saveArchiveCards, "%d ", cards[i]); 
    }       
    if(saveArchiveCardsAux != NULL){
        for(int i = 0; i< 16; i++)      
            fprintf(saveArchiveCardsAux, "%d ", cardsAux[i]);
    }   
    fclose(saveArchiveCards);
    fclose(saveArchiveCardsAux);
}


void continueGameOpc(int opcContinue){  // Funcao que salva se o usuario que continuar o game ou não
    
    if (opcContinue > 0){
        FILE *continueGame;
        continueGame = fopen("saveGameData/continueOption.txt", "w+");
        
        if(continueGame != NULL)
            fprintf(continueGame, "%d ", opcContinue);
        
        fclose(continueGame);
    }
}


// Return: 1 para usar o save, 2 para começar novo jogo
int stateContinue(){  // Funcao que retorna o estado do continue do game
    FILE *stateConti;
    int state;
    stateConti = fopen("saveGameData/continueOption.txt", "r");
    
    if(stateConti != NULL){
        fscanf(stateConti, "%d", &state);
        return state;
    }
    return 2;
}


#ifndef HEARDESSAVE_H_INCLUDED
#define HEARDESSAVE_H_INCLUDED
 
int stateContinue(); 
void saveGameProgress(int cards[16], int cardsAux[16]);
void continueGameOpc(int opcContinue);

#endif // HEARDESFUNCS_H_INCLUDED