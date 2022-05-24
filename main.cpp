#include "Bitmap.cpp"
#include "Matrix.cpp"
#include <iostream>

int main()
{
    Matrix *matrix = new Matrix(50, 50);

    // Picking color
    CurrentColor purple = CurrentColor(78, 50, 168);
    CurrentColor red = CurrentColor(204, 10, 10);

    matrix->pen(purple, 0, 49, 49, 0, 3);
    matrix->pen(red, 0, 0, 49, 49, 2);
    matrix->negativeFilter();
    Bitmap *image_test = new Bitmap(matrix->getMatrix(), matrix->getHeight(), matrix->getWidth(), "lineas.bmp");
}