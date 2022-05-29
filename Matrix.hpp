#ifndef Matrix_h
#define Matrix_h

#include "Pixel.hpp"
#include "CurrentColor.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>

class Matrix
{
public:
    Matrix(int height, int width);
    void setSize(int height, int width);
    void createMatrix();
    void loadMatrix();
    void initializePixels();
    void printMatrix(Pixel ***matrix, bool traspose = false);
    Pixel ***getMatrix();
    Pixel ***setMatrix(Pixel ***matrix);
    void setColor(Pixel *pixel, CurrentColor color);
    Pixel *getPixel(int i, int j);
    int getHeight();
    int getWidth();

    void pencil(CurrentColor color, int i, int j, int line_width);
    void pen(CurrentColor color, int x1, int y1, int x2, int y2, int line_width);
    void eraser(int i, int j, int eraser_width);

    void grayScaleFilter();
    void negativeFilter();
    void ramFilter();
    void sepiaFilter();

    void traspose();
    void flipX();
    void flipY();
    void rotate();

    void BFS(CurrentColor picked_color, CurrentColor new_color, int x, int y);
    void paintFill(CurrentColor picked_color, CurrentColor new_color, int x, int y);
    void setMemoryFlag(int flag);

    void polygon(CurrentColor color, int x, int y, int l, int n, int line_width);
    void rectangle(CurrentColor color, int x, int y, int b, int h, int line_width);
    void circle(CurrentColor color, int h, int k, int r, int line_width);
    
    void deleteMatrix(Pixel ***temp_matrix);
    void switchDimentions();

private:
    int height, width;
    Pixel ***matrix;
    int memoryFlag;
};

#endif