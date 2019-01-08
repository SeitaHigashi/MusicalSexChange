#pragma once

typedef struct {
    short left;
    short right;
} STEREO_WAVE;

typedef struct {
    short wave;
} MONAURAL_WAVE;

typedef struct{
    unsigned char LIST_CHUNK[4];
    unsigned int size;
    unsigned char* data;
} LIST;

typedef struct {
    unsigned char defineFormat[4];
    unsigned int fmtSize;
    unsigned short formatID;
    unsigned short channelSize;
    unsigned int samplingRate;
    unsigned int dataSpeed;
    unsigned short blockSize;
    unsigned short bps; //bit per sample
} FMT;

typedef struct {
    unsigned char DATA_CHUNK[4];
    unsigned int waveSize;
    void* wave;
} DATA;

typedef struct {
    unsigned char WAVE_HEAD[4];
    FMT fmt;
    LIST list;
    DATA data;
} WAVE;

typedef struct {
    unsigned char RIFF_HEAD[4];
    unsigned int fileSize;
    WAVE wave;
} RIFF;

RIFF* wav_read(char*);

void wav_write(char*, RIFF*);