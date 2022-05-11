#ifndef Matrix_h
#define Matrix_h

#include "Pixel.cpp"
#include <iostream>
#include <cmath>

class Matrix
{
public:
    Matrix(int height, int width);
    void setSize(int height, int width);
    void createMatrix();
    void initializePixels();
    void printMatrix();
    Pixel ***getMatrix();
    int getHeight();
    int getWidth();


    void line(int x1, int y1, int x2, int y2);

private:
    int height, width;
    Pixel ***matrix;
};

#endif