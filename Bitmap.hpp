#ifndef Bitmap_h
#define Bitmap_h

#include "Pixel.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#define FILE_HEADER_SIZE 14
#define INFO_HEADER_SIZE 40
#define BITS_PER_PIXEL 24

class Bitmap
{
public:
    Bitmap(Pixel ***matrix, int height, int width);
    void generateBitmapImage(Pixel ***matrix, int height, int width);
    void fillFourBytes(unsigned char *array, int value, int init_byte);
    unsigned char *createBitmapFileHeader(int height, int width);
    unsigned char *createBitmapInfoHeader(int height, int width);
    unsigned char *generateBlankCanvas(int height, int width);
    unsigned char *matrixToPixelArray(Pixel ***matrix, int height, int width);
private:
    int padding_bytes;
    int pixel_array_size;
};
#endif