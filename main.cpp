#include "Bitmap.cpp"
#include "Matrix.cpp"
#include <iostream>

int main()
{
    Matrix *matrix = new Matrix(50, 50);
    matrix->line(0, 49, 49, 0);
    matrix->printMatrix();
    Bitmap *image_test = new Bitmap(matrix->getMatrix(), matrix->getHeight(), matrix->getWidth());

    
}