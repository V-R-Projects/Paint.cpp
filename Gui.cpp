#include "Gui.hpp"

Gui::Gui(int height, int width)
{
    this->height = height;
    this->width = width;
    this->matrix = new Matrix(height, width);
    int argc = 0;
    QApplication app(argc, nullptr);
    RenderArea Window;
    app.exec();
}