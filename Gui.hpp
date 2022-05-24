#ifndef Gui_hpp
#define Gui_hpp

#include "Matrix.hpp"
#include "Bitmap.hpp"

#include <QApplication>
#include <QLabel>
#include <QWidget>

class Gui
{
private:
    int height, width;
    Matrix *matrix;

public:
    Gui(int height, int width);
    void createWindow();
    ~Gui();
};

#endif