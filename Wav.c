#include "Wav.h"
#include <stdlib.h>
#include <stdio.h>

WAVE_HEAD wav_read(char* path){
    FILE* fp;

    if((fp = fopen(path,"rb")) == NULL){
        puts("can't open file");
        exit(1);
    }

    fread(&wav,(size_t)9,sizeof(int),fp);

    fread(&(wav.expansions),1,sizeof(short),fp);

    wav.expansions.expansion = (char*)calloc(wav.expansions.size,sizeof(char));
    if(wav.expansions.expansion == NULL){
        puts("alloc error");
        exit(1);
    }

    fread(wav.expansions.expansion, wav.expansions.size, sizeof(char), fp);

    wav.wave = calloc(1,wav.waveSize);
    if(wav.wave == NULL){
        puts("alloc error");
        exit(1);
    }

    fread(wav.wave,wav.waveSize,1,fp);
    
    puts("wav read successful");
    return wav;
}