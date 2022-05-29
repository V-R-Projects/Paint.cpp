#ifndef Pixel_h
#define Pixel_h

#include "CurrentColor.hpp"
#include <iostream>

class Pixel
{
public:
    Pixel();
    void print();
    void setPixelColor(int r, int g, int b);
    void setPixelColor(CurrentColor color);
    int getRed();
    int getGreen();
    int getBlue();
    CurrentColor getColor();

private:
    int R;
    int G;
    int B;
};

#endif