#include "Window.cpp"
#include "Pixel.cpp"
#include "RenderArea.cpp"
#include "InitWindow.cpp"
#include <iostream>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    InitWindow w;
    w.show();
    app.exec();
}