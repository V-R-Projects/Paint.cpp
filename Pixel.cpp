#include "Pixel.hpp"

using namespace std;

Pixel::Pixel()
{
    setColor(255, 255, 255);
}

void Pixel::setColor(int r, int g, int b)
{
    R = r;
    G = g;
    B = b;
}

void Pixel::print()
{
    cout << "Pixel: " << R << ", " << G << ", " << B << endl;
}