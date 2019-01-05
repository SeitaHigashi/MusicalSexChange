#include "Conversion.h"

unsigned short getSamplingLate(){
    return wav.wave.fmt.samplingLate;
}

unsigned short setSamplingLate(unsigned short late){
    wav.wave.fmt.samplingLate = late;
}