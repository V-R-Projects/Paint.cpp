#include "Pixel.hpp"

using namespace std;

Pixel::Pixel()
{
    setPixelColor(255, 255, 255);
}

void Pixel::setPixelColor(int r, int g, int b)
{
    R = r;
    G = g;
    B = b;
}
void Pixel::setPixelColor(CurrentColor color)
{
    R = color.getR();
    G = color.getG();
    B = color.getB();
}

void Pixel::print()
{
    cout << "Pixel: " << R << ", " << G << ", " << B << endl;
}

int Pixel::getRed()
{
    return R;
}
int Pixel::getGreen()
{
    return G;
}
int Pixel::getBlue()
{
    return B;
}
CurrentColor Pixel::getColor()
{
    return CurrentColor(R, G, B);
}