#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Chaine.h"


Chaines* lectureChaine(FILE *f){
    Chaines *ch = (Chaines*)malloc(sizeof(Chaines));

    char input[256];
    fgets(input, sizeof(input), f);
    sscanf(input,"NbChain: %d",&(ch->nbChaines));
    fgets(input, sizeof(input), f);
    sscanf(input,"Gamma: %d",&(ch->gamma));

    while(!feof(f)){
        
        fgets(input, sizeof(input), f);
        sscanf(input,"%d",&(ch->nbChaines));
    }

    

    return ch;
}

int main(){

    FILE *fich = fopen("00014_burma.cha","r");

    char input[256];
    fgets(input, sizeof(input), fich);
    
    puts(input);

    return 0;
}