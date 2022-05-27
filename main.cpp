#include "Window.cpp"
#include "RenderArea.cpp"
#include <iostream>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Window w;
    w.show();
    app.exec();
}