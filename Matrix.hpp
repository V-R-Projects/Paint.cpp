#ifndef Matrix_h
#define Matrix_h

#include "Pixel.cpp"
#include <iostream>

class Matrix
{
public:
    Matrix(int height, int width);
    void setSize(int height, int width);
    void createMatrix();
    void initializePixels();
    void printMatrix();

private:
    int height, width;
    Pixel ***matrix;
};

#endif