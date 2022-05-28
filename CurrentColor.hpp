#ifndef CurrentColor_h
#define CurrentColor_h

#include <iostream>

class CurrentColor
{
public:
    CurrentColor(int R, int G, int B)
    {
        r = R;
        g = G;
        b = B;
    };
    int getR() { return r; };
    int getG() { return g; };
    int getB() { return b; };
    CurrentColor addToColor(int add);

private:
    int r;
    int g;
    int b;
};


#endif