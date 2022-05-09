#include "Bitmap.hpp"

Bitmap::Bitmap()
{
    // empty
}

char *Bitmap::createBitmapInfoHeader(int height, int width)
{
    int image_size = height * width * BYTES_PER_PIXEL;

    static unsigned char infoHeader[] = {
        40, 0, 0, 0,  /// header size
        0, 0, 0, 0,   /// image width
        0, 0, 0, 0,   /// image height
        1, 0,         /// number of color planes
        24, 0,        /// bits per pixel
        0, 0, 0, 0,   /// compression
        0, 0, 0, 0,   /// image size
        19, 11, 0, 0, /// horizontal resolution
        19, 11, 0, 0, /// vertical resolution
        0, 0, 0, 0,   /// colors in color table
        0, 0, 0, 0,   /// important color count
    };

    fillFourBytes(infoHeader, width, 4);
    fillFourBytes(infoHeader, height, 8);
    fillFourBytes(infoHeader, image_size, 20);
}

void Bitmap::fillFourBytes(unsigned char *array, int value, int init_byte)
{
    for (int i = init_byte; i < init_byte + 4; i++)
    {
        array[i] = (unsigned char)(value >> (8 * (i - init_byte)));
    }
}