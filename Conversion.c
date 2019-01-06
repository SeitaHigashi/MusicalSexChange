#include "Conversion.h"

void setSamplingRate(unsigned int rate, RIFF* wav){
    wav->wave.fmt.samplingRate = rate;
}

void setBeginTime(unsigned int time, RIFF* wav){
    unsigned int rate = wav->wave.fmt.samplingRate;
    unsigned short blocksize = wav->wave.fmt.blockSize;
    wav->wave.data.wave += rate*blocksize*time;
    wav->wave.data.waveSize -= rate*blocksize*time;
}