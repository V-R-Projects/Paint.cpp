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
    Bitmap(Pixel ***matrix, int height, int width, char file_name[]);
    Bitmap(char file_name[]);
    void generateBitmapImage(Pixel ***matrix, int height, int width, char file_name[]);
    void fillFourBytes(unsigned char *array, int value, int init_byte);
    void readBMP(char file_name[]);
    unsigned char *createBitmapFileHeader(int height, int width);
    unsigned char *createBitmapInfoHeader(int height, int width);
    unsigned char *generateBlankCanvas();
    unsigned char *matrixToPixelArray(Pixel ***matrix, int height, int width);
    Pixel ***pixelArrayToMatrix();
    int getHeight();
    int getWidth();

private:
    unsigned char *pixel_array;
    int padding_bytes;
    int pixel_array_size;
    int height;
    int width;
};
#endif