#include "Wav.h"
#include <stdlib.h>
#include <stdio.h>

void tag_copy(char* src, char* dist){
    int i;
    for(i=0; i < 4; i++) dist[i] = src[i];
}

int tag_comparison(char* a, char* b){
    return *(int*)a == *(int*)b;
}

void wav_read(char* path){
    FILE* fp;
    char buff[4];

    if((fp = fopen(path,"rb")) == NULL){
        puts("can't open file");
        exit(1);
    }

    fread(buff, sizeof(char), 4, fp);
    if(tag_comparison(buff, "RIFF")){
        tag_copy(buff, wav.RIFF_HEAD);
        fread(&(wav.fileSize), sizeof(unsigned int), 1, fp);

        fread(buff, sizeof(char), 4, fp);
        if(tag_comparison(buff,"WAVE")){
            tag_copy(buff, wav.wave.WAVE_HEAD);

            fread(buff, sizeof(char), 4, fp);
            if(tag_comparison(buff, "fmt ")){
                tag_copy(buff, wav.wave.fmt.defineFormat);

                fread(&(wav.wave.fmt.fmtSize), sizeof(FMT) - 4, 1, fp);

                fread(buff, sizeof(char), 4, fp);
                if(tag_comparison(buff, "LIST")){
                    tag_copy(buff, wav.wave.list.LIST_CHUNK);

                    fread(&(wav.wave.list.size), sizeof(unsigned int), 1, fp);

                    wav.wave.list.data = (unsigned char *)calloc(wav.wave.list.size, sizeof(char));
                    fread(wav.wave.list.data, wav.wave.list.size, 1, fp);
                }

                fread(buff, sizeof(char), 4, fp);
                if (tag_comparison(buff, "data"))
                {
                    tag_copy(buff, wav.wave.data.DATA_CHUNK);

                    fread(&(wav.wave.data.waveSize), sizeof(unsigned int), 1, fp);

                    wav.wave.data.wave = calloc(wav.wave.data.waveSize, 1);
                    fread(wav.wave.data.wave, wav.wave.data.waveSize, 1, fp);
                }
                else
                {
                    puts("unsupported files");
                    exit(1);
                }
            }
            else
            {
                puts("unsupported files");
                exit(1);
            }

        }
        else
        {
            puts("unsupported files");
            exit(1);
        }

    }
    else
    {
        puts("unsupported files");
        exit(1);
    }


    puts("wav read successful");
}

void wav_write(char* path){
    FILE* fp;

    if((fp = fopen(path,"wb")) == NULL){
        puts("can't open file");
        exit(1);
    }

}