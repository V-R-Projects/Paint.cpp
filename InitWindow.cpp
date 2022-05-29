#include "InitWindow.hpp"

InitWindow::InitWindow()
{
    this->instructionLabel = new QLabel("Please enter the width and height of the matrix:");
    this->widthLabel = new QLabel("Width:");
    this->heightLabel = new QLabel("Height:");
    this->widthSpinBox = new QSpinBox();
    this->heightSpinBox = new QSpinBox();
    this->okButton = new QPushButton("OK");

    widthSpinBox->setRange(1, 1000);
    heightSpinBox->setRange(1, 1000);

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(this->instructionLabel, 0, 0, 1, 2);
    layout->addWidget(this->widthLabel, 1, 0);
    layout->addWidget(this->widthSpinBox, 1, 1);
    layout->addWidget(this->heightLabel, 2, 0);
    layout->addWidget(this->heightSpinBox, 2, 1);
    layout->addWidget(this->okButton, 3, 0, 1, 2);

    this->setLayout(layout);
    this->setWindowTitle("Matrix Initialization");

    connect(this->okButton, &QAbstractButton::clicked, this, &InitWindow::okButtonClicked);
}

void InitWindow::okButtonClicked()
{
    Window *window = new Window(widthSpinBox->value(), heightSpinBox->value());
    window->show();
    this->hide();
}