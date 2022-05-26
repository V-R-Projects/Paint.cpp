#include "Bitmap.hpp"

using namespace std;

Bitmap::Bitmap(Pixel ***matrix, int height, int width, char file_name[])
{   
    padding_bytes = (4 - (width * BITS_PER_PIXEL / 8) % 4) % 4;
    pixel_array_size = height * width * (BITS_PER_PIXEL / 8) + padding_bytes * height;
    generateBitmapImage(matrix, height, width, file_name);
}

void Bitmap::generateBitmapImage(Pixel ***matrix, int height, int width, char file_name[])
{
    FILE *image_file = fopen(file_name, "wb");

    unsigned char *file_header = createBitmapFileHeader(height, width);
    unsigned char *info_header = createBitmapInfoHeader(height, width);
    unsigned char *pixel_array = matrixToPixelArray(matrix, height, width);

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
    fillFourBytes(info_header, pixel_array_size, 20);

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
    unsigned char *pixel_array = (unsigned char *)malloc(pixel_array_size);

    for (int i = 0; i < pixel_array_size; i++)
    {
        pixel_array[i] = 34;
    }

    return pixel_array;
}

unsigned char *Bitmap::matrixToPixelArray(Pixel ***matrix, int height, int width)
{
    unsigned char *pixel_array = (unsigned char *)malloc(pixel_array_size);
    int c = 0;
    for (int i = height - 1; i >= 0; i--)
    {
        for (int j = 0; j < width; j++)
        {
            pixel_array[c] = matrix[i][j]->getBlue();
            pixel_array[c + 1] = matrix[i][j]->getGreen();
            pixel_array[c + 2] = matrix[i][j]->getRed();
            c += 3;
        }
        c += padding_bytes;
    }

    return pixel_array;
}