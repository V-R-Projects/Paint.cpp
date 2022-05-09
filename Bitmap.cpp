#include "Bitmap.hpp"

using namespace std;

Bitmap::Bitmap(int height, int width)
{
    pixel_array_size = height * width * (BITS_PER_PIXEL / 8);
    generateBitmapImage(height, width);
}

void Bitmap::generateBitmapImage(int height, int width)
{
    FILE *image_file = fopen("canvas.bmp", "wb");

    unsigned char *file_header = createBitmapFileHeader(height, width);
    unsigned char *info_header = createBitmapInfoHeader(height, width);
    unsigned char *pixel_array = generateBlankCanvas(height, width);

    fwrite(file_header, 1, FILE_HEADER_SIZE, image_file);
    fwrite(info_header, 1, INFO_HEADER_SIZE, image_file);
    fwrite(pixel_array, 1, pixel_array_size, image_file);

    cout << "Bitmap Image created succesfully!" << endl;
}

unsigned char *Bitmap::createBitmapFileHeader(int height, int width)
{
    int file_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (width * height * (BITS_PER_PIXEL / 8));

    static unsigned char file_header[] = {
        'B', 'M',    /// signature
        0, 0, 0, 0,  /// image file size in bytes
        0, 0, 0, 0,  /// reserved
        54, 0, 0, 0, /// start of pixel array
    };

    fillFourBytes(file_header, file_size, 2);

    return file_header;
}

unsigned char *Bitmap::createBitmapInfoHeader(int height, int width)
{
    int image_size = height * width * BITS_PER_PIXEL;

    static unsigned char info_header[] = {
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

    fillFourBytes(info_header, width, 4);
    fillFourBytes(info_header, height, 8);
    fillFourBytes(info_header, image_size, 20);

    return info_header;
}

void Bitmap::fillFourBytes(unsigned char *array, int value, int init_byte)
{
    for (int i = init_byte; i < init_byte + 4; i++)
    {
        array[i] = (unsigned char)(value >> (8 * (i - init_byte)));
    }
}

unsigned char *Bitmap::generateBlankCanvas(int height, int width)
{
    unsigned char *bitmap = (unsigned char *)malloc(pixel_array_size);

    for (int i = 0; i < pixel_array_size; i++)
    {
        bitmap[i] = 255;
    }

    return bitmap;
}