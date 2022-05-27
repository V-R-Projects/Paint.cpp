#include "Gui.hpp"

Gui::Gui(int height, int width)
{
    this->height = height;
    this->width = width;
    this->matrix = new Matrix(height, width);
    int argc = 0;
    QApplication app(argc, nullptr);
    QLabel hola("<center>Ejemplo Qt para Ubunlog</center>");
    hola.setWindowTitle("Mi primer programa Qt");
    hola.resize(600, 400);
    hola.show();
    app.exec();
}