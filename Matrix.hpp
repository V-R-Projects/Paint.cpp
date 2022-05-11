#ifndef Matrix_h
#define Matrix_h

#include "Pixel.cpp"
#include <iostream>

class Matrix
{
public:
    Matrix();
    static Matrix *getInstance();
    static void setSize(int height, int width);
    void createMatrix();
    void initializePixels();

    static int height;
    static int width;

private:
    static Matrix *matrix_instance;
    Pixel **matrix;
};

#endif