#include "Interactive_CLI.h"
#include <stdio.h>

void interactive(){
    char editfile[256];
    FILE* fp;
    RIFF* wav;

    do
    {
        printf("Please enter the file to edit: ");
        scanf("%s", editfile);
        wav = wav_read(editfile);
    } while ( wav == NULL);
    while (1)
    {
        return;
    }

   return ;
}