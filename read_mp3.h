#ifndef READ_MP3_H
#define READ_MP3_H

#include <stdio.h>

typedef struct mp3Info{
    char title[30];
    char artist[30];
    char album[30];
    int trackNumber;
}mp3Info;

int extractInf(char* filename, mp3Info* info);


#endif
