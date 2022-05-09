#ifndef Bitmap_h
#define Bitmap_h

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#define FILE_HEADER_SIZE 14
#define INFO_HEADER_SIZE 40
#define BYTES_PER_PIXEL 24 

class Bitmap 
{
    public:
        Bitmap();
        void generateBitmapImage();
        char *createBitmapFileHeader();
        char *createBitmapInfoHeader(int height, int width);
        void fillFourBytes(unsigned char *array, int value, int init_byte);
};
#endif