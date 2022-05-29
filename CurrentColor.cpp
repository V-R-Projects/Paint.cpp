#include "CurrentColor.hpp"

CurrentColor CurrentColor::addToColor(int add)
{
    r = (r + add) % 256;
    g = (g + add) % 256;
    b = (b + add) % 256;
    return CurrentColor(r, g, b);
}