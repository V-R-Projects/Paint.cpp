#include <iostream>

void fillFourBytes(unsigned char *array, int value, int init_byte)
{
    for (int i = init_byte; i < init_byte + 4; i++)
    {
        array[i] = (unsigned char)(value >> (8 * (i - init_byte)));
    }
}

int main()
{
    int file_size = 80;
    static unsigned char file_header[] = {
        'B', 'M',    /// signature
        0, 0, 0, 0,  /// image file size in bytes
        0, 0, 0, 0,  /// reserved
        54, 0, 0, 0, /// start of pixel array
    };
    fillFourBytes(file_header, file_size, 2);
    for (int i = 0; i < sizeof(file_header); i++)
    {
        int number = file_header[i];
        std::cout << number << " ";
    }
}