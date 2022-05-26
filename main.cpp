#include "Bitmap.cpp"
#include "Matrix.cpp"
#include <iostream>

int main()
{
    Matrix *matrix = new Matrix(1000, 1000);

    // Picking color
    CurrentColor purple = CurrentColor(78, 50, 168);
    CurrentColor red = CurrentColor(204, 10, 10);

    // matrix->pen(purple, 0, 24, 49, 0, 2);
    // matrix->pen(red, 0, 0, 25, 25, 3);
    // matrix->pencil(purple, 5, 5, 3);
    matrix->polygon(purple, 5, 5, 200, 8, 1);
    Bitmap *image_test = new Bitmap(matrix->getMatrix(), matrix->getHeight(), matrix->getWidth(), "original.bmp");
    matrix->rotate();
    Bitmap *image_test2 = new Bitmap(matrix->getMatrix(), matrix->getHeight(), matrix->getWidth(), "rotate.bmp");
}