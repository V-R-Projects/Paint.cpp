#ifndef Matrix_h
#define Matrix_h

#include "Pixel.hpp"
#include <iostream>

class Matrix
{
    public:
        Matrix();
        static Matrix *getInstance();
        static void setSize(int height, int width);
        void createMatrix();
        void initializePixels();

    private:
        static Matrix *matrix_instance;
        static int height;
        static int width;
        Pixel **matrix;
};

#endif