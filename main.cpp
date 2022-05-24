#include "Bitmap.cpp"
#include "Matrix.cpp"
#include "Gui.cpp"
#include <iostream>

int main()
{
    Matrix *matrix = new Matrix(50, 50);

    // cuando se selecciona un color
    CurrentColor black = CurrentColor(0, 0, 255);

    matrix->line(black, 0, 49, 49, 0);
    std::string file_name = "test.bmp";
    Bitmap *image_test = new Bitmap(matrix->getMatrix(), matrix->getHeight(), matrix->getWidth(), (char *)file_name.c_str());

    Gui *gui = new Gui(matrix->getHeight(), matrix->getWidth());
}