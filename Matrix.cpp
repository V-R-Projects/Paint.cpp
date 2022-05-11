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
    matrix = (Pixel ***)malloc(sizeof(Pixel **) * height);
    for (int i = 0; i < height; i++)
    {
        matrix[i] = (Pixel **)malloc(sizeof(Pixel *) * width);
    }
    initializePixels();
}

void Matrix::printMatrix()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout<<i<<","<<j<<": ";
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

Pixel ***Matrix::getMatrix()
{
    return matrix;
}

int Matrix::getHeight()
{
    return height;
}

int Matrix::getWidth()
{
    return width;
}

void Matrix::line(int x1, int y1, int x2, int y2)
{
    if (x2 - x1 == 0)
    {
        if (y2 < y1)
        {
            int temp = y1;
            y1 = y2;
            y2 = temp;
        }
        for (int i = y1; i <= y2; i++)
        {
            matrix[i][x1]->setColor(255, 0, 0);
        }
    }
    else
    {

        float m = (float)(y2 - y1) / (float)(x2 - x1);
        printf("m: %f\n", m);
        float b = y1 - (m * x1);
        if (x2 < x1)
        {
            int temp = x1;
            x1 = x2;
            x2 = temp;
        }
        int old_y = round(m * x1 + b);
        for (int i = x1; i <= x2; i++)
        {
            int new_y = round(m * i + b);
            if (new_y == old_y)
            {
                matrix[new_y][i]->setColor(255, 0, 0);
            }
            else
            {
                if (m >= 0)
                {
                    for (int j = old_y+1; j <= new_y; j++)
                    {
                        matrix[j][i]->setColor(255, 0, 0);
                    }
                }
                else
                {
                    for (int j = old_y-1; j >= new_y; j--)
                    {
                        matrix[j][i]->setColor(255, 0, 0);
                    }
                }
            }
            old_y = new_y;
        }
    }
}