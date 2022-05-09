#ifndef Bitmap_h
#define Bitmap_h

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
    Bitmap(int height, int width);
    void generateBitmapImage(int height, int width);
    unsigned char* createBitmapFileHeader(int height, int width);
    unsigned char* createBitmapInfoHeader(int height, int width);
    void fillFourBytes(unsigned char *array, int value, int init_byte);
    unsigned char *generateBlankCanvas(int height, int width);
private:
    int pixel_array_size;
};
#endif