#include "Bitmap.cpp"
#include "Matrix.cpp"
#include <iostream>

int main()
{
    Matrix *matrix = new Matrix(500, 500);

    // Picking color
    CurrentColor purple = CurrentColor(78, 50, 168);
    CurrentColor red = CurrentColor(204, 10, 10);
    CurrentColor blue = CurrentColor(0, 0, 254);
    CurrentColor white = CurrentColor(255, 255, 255);
    CurrentColor black = CurrentColor(0, 0, 0);

    matrix->circle(purple, 250, 250, 50, 2);
    matrix->circle(purple, 270, 270, 50, 2);


    matrix->paintFill(white, red, 210, 250);
    matrix->paintFill(white, black, 250, 250);
    matrix->paintFill(white, blue, 310, 270);
    matrix->pencil(red, 310, 270, 2);

    Bitmap *image_test = new Bitmap(matrix->getMatrix(), matrix->getHeight(), matrix->getWidth(), "original.bmp");
    
    matrix->rotate();
    Bitmap *image_test2 = new Bitmap(matrix->getMatrix(), matrix->getHeight(), matrix->getWidth(), "rotate.bmp");
}