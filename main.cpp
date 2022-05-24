#include "Bitmap.cpp"
#include "Matrix.cpp"
#include <iostream>

int main()
{
    Matrix *matrix = new Matrix(50, 50);

    // cuando se selecciona un color
    CurrentColor black = CurrentColor(0, 0, 255);

    matrix->line(black, 0, 49, 49, 0);
    Bitmap *image_test = new Bitmap(matrix->getMatrix(), matrix->getHeight(), matrix->getWidth(), "linea_azul.bmp");

}