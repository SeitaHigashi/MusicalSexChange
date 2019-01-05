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
    printf("sampling late:%dhz\n",wav.samplingLate);

    fread(&(wav.expansions),1,sizeof(short),fp);
    wav.expansions.expansion = (char*)calloc(wav.expansions.size,sizeof(char));
    fread(wav.expansions.expansion, wav.expansions.size, sizeof(char), fp);

    wav.wave = calloc(1,wav.waveSize);
    fread(wav.wave,wav.waveSize,1,fp);
    
    return wav;
}