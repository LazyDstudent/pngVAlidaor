/*89 50 4E 47 0D 0A 1A 0A*/

/*

+------------------+------------------+------------------------+-------------------+
| PNG Signature    | IHDR Chunk       | Other Chunks (e.g., IDAT, PLTE) | IEND Chunk      |
| (8 bytes)        | (13 bytes)       | (Variable length)       | (12 bytes)        |
+------------------+------------------+------------------------+-------------------+

check the first 8
*/

#include <stdio.h>
#include "pnger.h"

bool is_png(FILE *fp) {
    if (fp == NULL) {
        return false;
    }

    unsigned char png_SIG[8];
    unsigned char png_RSIG[8] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};

    size_t bytesCHECK = fread(png_SIG, sizeof(char), sizeof(char)*8 , fp);
    if (bytesCHECK != 8) {
        return false;
    }
    
    for (int i = 0 ; i < 8 ; i++) {
        if(png_SIG[i] != png_RSIG[i]) {
            return false; 
        }
    }

    return true; //passed all checks so we can say its prolly a png
}
