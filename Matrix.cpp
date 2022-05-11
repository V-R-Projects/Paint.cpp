#include "Matrix.hpp"
#include <iostream>

Matrix::Matrix(int height, int width)
{
    this->height = height;
    this->width = width;
    createMatrix();
}

void Matrix::setSize(int h, int w)
{
    height = h;
    width = w;
}

void Matrix::createMatrix()
{
    matrix = (Pixel ***) malloc(sizeof(Pixel **)*height);
    for (int i = 0; i < height; i++)
    {
        matrix[i] = (Pixel **) malloc(sizeof(Pixel *) * width);
    }
    initializePixels();
    printMatrix();
}

void Matrix::printMatrix()
{
    for(int i = 0; i<height; i++)
    {
        for(int j = 0; j<width; j++)
        {
            matrix[i][j]->print();
        }
    }
}

void Matrix::initializePixels()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            matrix[i][j] = new Pixel();
        }
    }
}