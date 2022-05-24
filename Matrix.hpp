#ifndef Matrix_h
#define Matrix_h

#include "Pixel.cpp"
#include "CurrentColor.hpp"
#include <iostream>
#include <string>
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

    void pencil(CurrentColor color, int i, int j, int line_width);
    void pen(CurrentColor color, int x1, int y1, int x2, int y2, int line_width);
    void setColor(Pixel * pixel, CurrentColor color);
    Pixel *getPixel(int i, int j);
    void grayScaleFilter();
    void negativeFilter();
    void rotate();
    void deleteMatrix();
    void switchDimentions();
    void eraser(int i, int j, int eraser_width);

private:
    int height, width;
    Pixel ***matrix;
};

#endif