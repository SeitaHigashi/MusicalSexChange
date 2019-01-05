#pragma once


typedef struct {
    unsigned short size;
    unsigned char* expansion;
} WAVE_EXPANSIONS;

typedef struct {
    short left;
    short right;
} STEREO_WAVE;

typedef struct {
    short wave;
} MONAURAL_WAVE;

typedef struct {
    unsigned char RIFF_HEAD[4];
    unsigned int fileSize;
    unsigned char WAVE_HEAD[4];
    unsigned char defineFormat[4];
    unsigned int fmtSize;
    unsigned short formatID;
    unsigned short channelSize;
    unsigned int samplingLate;
    unsigned int dataSpeed;
    unsigned short blockSize;
    unsigned short bps; //bit per sample
    unsigned char DATA_CHUNK[4];
    unsigned int waveSize;
    WAVE_EXPANSIONS expansions;
    void* wave;
} WAVE_HEAD;

WAVE_HEAD wav;

WAVE_HEAD wav_read(char*);