#include "read_mp3.h"
#include <stdio.h>
#include <string.h>


int main(){
    char* filename = "/Users/olgudegirmenci/Downloads/Bayhan-Benim-Hala-Umudum-Var.mp3";
    mp3Info info;


    if (extractInf(filename, &info) == 0){
        printf("Title: %s\n", info.title);
        printf("Artist: %s\n", info.artist);
        printf("Album: %s\n", info.album);
        printf("Track Number: %d\n", info.trackNumber);
    } else {
        printf("Failed to extract mp3 information\n");
    }

    return 0;
}


int extractInf(char* filename, mp3Info* info){
    FILE* file = fopen(filename, "rb");
    if (!file){
        printf("Error openning file!");
        return -1;
    }
    /*fseek() is used to move the file pointer associated with a given file to a specific position. */
    fseek(file, -128, SEEK_END);

    char buffer[128];
    /*function reads data from the given stream into the array pointed to, by ptr */
    fread(buffer, 1, 128, file);

    /*strncmp() function is used to compare at most a
    specified number of characters from two null-terminated strings. */
    if (strncmp(buffer, "TAG", 3) == 0) {
        // Extract the title, artist, and album (30 bytes each)
        strncpy(info->title, buffer + 3, 30);
        strncpy(info->artist, buffer + 33, 30);
        strncpy(info->album, buffer + 63, 30);

        // The track number is located in buff[126] (if present)
        info->trackNumber = buffer[126];
        fclose(file);
        return 0;
    } else {
        printf("No ID3v1 tag found.\n");
        fclose(file);
        return -1;
    }
}
