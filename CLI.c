#include "CLI.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

int main(int argc, char* argv[]){
    int i, opt;
    RIFF* wav;
    int longindex;
    struct option longopts[] = {
        { "samplingrate",   required_argument,  NULL,   's'},
        { "begin",          required_argument,  NULL,   'b'},
        { "end",            required_argument,  NULL,   'e'},
        { "interactive",    no_argument,        NULL,   'i'},
        { "view",           no_argument,        NULL,   'v'},
        { 0,                0,                  0,       0 }
    };

    char* filepath[2]; // [0] = inputfile, [1] = outputfile
    unsigned int samplingRate = 0;
    unsigned short view = -1;
    unsigned int begin = 0;
    unsigned int end = __UINT32_MAX__;

    opterr = 0;

    
    while((opt = getopt_long(argc, argv, "s:b:e:iv", longopts, &longindex)) != -1){
        switch (opt) {
            case 's':
                samplingRate = atoi(optarg);
                break;
            case 'b':
                begin = atoi(optarg);
                break;
            case 'e':
                end = atoi(optarg);
                break;
            case 'i':
                interactive();
                return 0;
                break;
            case 'v':
                view = 1;
                break;
            default:
                printf("error! \'%c\' \'%c\'\n", opt, optopt);
                return 1;
        }
    }

    for(i = 0; i + optind < argc; i++)filepath[i] = argv[i+optind];

    if((wav = wav_read(filepath[0])) == NULL)exit(1);

    if(view == 1){
        viewInformation(wav);
        return 0;
    }

    if(samplingRate != 0)
        setSamplingRate(samplingRate, wav);

    setBeginTime(begin, wav);

    if(end != __UINT32_MAX__)
        setEndTime(end - begin, wav);

    wav_write(filepath[1], wav);
    
    return 0;
}


 void viewInformation(RIFF* wav){
     printf("formatID:      %u\n",wav->wave.fmt.formatID);
     printf("channelSize:   %u\n",wav->wave.fmt.channelSize);
     printf("samplingRate:  %u\n",wav->wave.fmt.samplingRate);
     printf("dataSpeed:     %u\n",wav->wave.fmt.dataSpeed);
     printf("blockSize:     %u\n",wav->wave.fmt.blockSize);
     printf("bit/sample:    %u\n",wav->wave.fmt.bps);
     printf("waveSize:    %u\n",wav->wave.data.waveSize);
 }