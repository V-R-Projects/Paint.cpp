#ifndef Pixel_h
#define Pixel_h

#include <iostream>

class Pixel
{
    public:
        Pixel();
        void setColor(int r, int g, int b);

    private:
        int R;
        int G;
        int B;
};

#endif