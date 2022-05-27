#include "Window.hpp"

Window::Window()
{
        renderArea = new RenderArea;

        shapeComboBox = new QComboBox;
        shapeComboBox->addItem(tr("Polygon"), RenderArea::Polygon);
        shapeComboBox->addItem(tr("Rectangle"), RenderArea::Rect);
        shapeComboBox->addItem(tr("Rounded Rectangle"), RenderArea::RoundedRect);
        shapeComboBox->addItem(tr("Ellipse"), RenderArea::Ellipse);
        shapeComboBox->addItem(tr("Pie"), RenderArea::Pie);
        shapeComboBox->addItem(tr("Chord"), RenderArea::Chord);
        shapeComboBox->addItem(tr("Path"), RenderArea::Path);
        shapeComboBox->addItem(tr("Line"), RenderArea::Line);
        shapeComboBox->addItem(tr("Polyline"), RenderArea::Polyline);
        shapeComboBox->addItem(tr("Arc"), RenderArea::Arc);
        shapeComboBox->addItem(tr("Points"), RenderArea::Points);
        shapeComboBox->addItem(tr("Text"), RenderArea::Text);

        shapeLabel = new QLabel(tr("&Shape:"));
        shapeLabel->setBuddy(shapeComboBox);
        penWidthSpinBox = new QSpinBox;
        penWidthSpinBox->setRange(0, 20);
        penWidthSpinBox->setSpecialValueText(tr("0 (cosmetic pen)"));

        penWidthLabel = new QLabel(tr("Pen &Width:"));
        penWidthLabel->setBuddy(penWidthSpinBox);

        penStyleComboBox = new QComboBox;
        penStyleComboBox->addItem(tr("Solid"), static_cast<int>(Qt::SolidLine));
        penStyleComboBox->addItem(tr("Dash"), static_cast<int>(Qt::DashLine));
        penStyleComboBox->addItem(tr("Dot"), static_cast<int>(Qt::DotLine));
        penStyleComboBox->addItem(tr("Dash Dot"), static_cast<int>(Qt::DashDotLine));
        penStyleComboBox->addItem(tr("Dash Dot Dot"), static_cast<int>(Qt::DashDotDotLine));
        penStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoPen));

        penStyleLabel = new QLabel(tr("&Pen Style:"));
        penStyleLabel->setBuddy(penStyleComboBox);

        penCapComboBox = new QComboBox;
        penCapComboBox->addItem(tr("Flat"), Qt::FlatCap);
        penCapComboBox->addItem(tr("Square"), Qt::SquareCap);
        penCapComboBox->addItem(tr("Round"), Qt::RoundCap);

        penCapLabel = new QLabel(tr("Pen &Cap:"));
        penCapLabel->setBuddy(penCapComboBox);

        penJoinComboBox = new QComboBox;
        penJoinComboBox->addItem(tr("Miter"), Qt::MiterJoin);
        penJoinComboBox->addItem(tr("Bevel"), Qt::BevelJoin);
        penJoinComboBox->addItem(tr("Round"), Qt::RoundJoin);

        penJoinLabel = new QLabel(tr("Pen &Join:"));
        penJoinLabel->setBuddy(penJoinComboBox);

        brushStyleComboBox = new QComboBox;
        brushStyleComboBox->addItem(tr("Linear Gradient"),
                                    static_cast<int>(Qt::LinearGradientPattern));
        brushStyleComboBox->addItem(tr("Radial Gradient"),
                                    static_cast<int>(Qt::RadialGradientPattern));
        brushStyleComboBox->addItem(tr("Conical Gradient"),
                                    static_cast<int>(Qt::ConicalGradientPattern));
        brushStyleComboBox->addItem(tr("Texture"), static_cast<int>(Qt::TexturePattern));
        brushStyleComboBox->addItem(tr("Solid"), static_cast<int>(Qt::SolidPattern));
        brushStyleComboBox->addItem(tr("Horizontal"), static_cast<int>(Qt::HorPattern));
        brushStyleComboBox->addItem(tr("Vertical"), static_cast<int>(Qt::VerPattern));
        brushStyleComboBox->addItem(tr("Cross"), static_cast<int>(Qt::CrossPattern));
        brushStyleComboBox->addItem(tr("Backward Diagonal"), static_cast<int>(Qt::BDiagPattern));
        brushStyleComboBox->addItem(tr("Forward Diagonal"), static_cast<int>(Qt::FDiagPattern));
        brushStyleComboBox->addItem(tr("Diagonal Cross"), static_cast<int>(Qt::DiagCrossPattern));
        brushStyleComboBox->addItem(tr("Dense 1"), static_cast<int>(Qt::Dense1Pattern));
        brushStyleComboBox->addItem(tr("Dense 2"), static_cast<int>(Qt::Dense2Pattern));
        brushStyleComboBox->addItem(tr("Dense 3"), static_cast<int>(Qt::Dense3Pattern));
        brushStyleComboBox->addItem(tr("Dense 4"), static_cast<int>(Qt::Dense4Pattern));
        brushStyleComboBox->addItem(tr("Dense 5"), static_cast<int>(Qt::Dense5Pattern));
        brushStyleComboBox->addItem(tr("Dense 6"), static_cast<int>(Qt::Dense6Pattern));
        brushStyleComboBox->addItem(tr("Dense 7"), static_cast<int>(Qt::Dense7Pattern));
        brushStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoBrush));

        brushStyleLabel = new QLabel(tr("&Brush:"));
        brushStyleLabel->setBuddy(brushStyleComboBox);

        otherOptionsLabel = new QLabel(tr("Options:"));
        antialiasingCheckBox = new QCheckBox(tr("&Antialiasing"));

        transformationsCheckBox = new QCheckBox(tr("&Transformations"));
        connect(shapeComboBox, QOverload<int>::of(&QComboBox::activated),
                this, &Window::shapeChanged);
        connect(penWidthSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
                this, &Window::penChanged);
        connect(penStyleComboBox, QOverload<int>::of(&QComboBox::activated),
                this, &Window::penChanged);
        connect(penCapComboBox, QOverload<int>::of(&QComboBox::activated),
                this, &Window::penChanged);
        connect(penJoinComboBox, QOverload<int>::of(&QComboBox::activated),
                this, &Window::penChanged);
        connect(brushStyleComboBox, QOverload<int>::of(&QComboBox::activated),
                this, &Window::brushChanged);
        connect(antialiasingCheckBox, &QAbstractButton::toggled,
                renderArea, &RenderArea::setAntialiased);
        connect(transformationsCheckBox, &QAbstractButton::toggled,
                renderArea, &RenderArea::setTransformed);

        QGridLayout *mainLayout = new QGridLayout;
        mainLayout->setColumnStretch(0, 1);
        mainLayout->setColumnStretch(2, 1);
        mainLayout->addWidget(renderArea, 0, 0, 8, 1);
        mainLayout->addWidget(shapeLabel, 0, 1, Qt::AlignRight);
        mainLayout->addWidget(shapeComboBox, 0, 2);
        mainLayout->addWidget(penWidthLabel, 1, 1, Qt::AlignRight);
        mainLayout->addWidget(penWidthSpinBox, 1, 2);
        mainLayout->addWidget(penStyleLabel, 2, 1, Qt::AlignRight);
        mainLayout->addWidget(penStyleComboBox, 2, 2);
        mainLayout->addWidget(penCapLabel, 3, 1, Qt::AlignRight);
        mainLayout->addWidget(penCapComboBox, 3, 2);
        mainLayout->addWidget(penJoinLabel, 4, 1, Qt::AlignRight);
        mainLayout->addWidget(penJoinComboBox, 4, 2);
        mainLayout->addWidget(brushStyleLabel, 5, 1, Qt::AlignRight);
        mainLayout->addWidget(brushStyleComboBox, 5, 2);
        mainLayout->addWidget(otherOptionsLabel, 6, 1, Qt::AlignRight);
        mainLayout->addWidget(antialiasingCheckBox, 6, 2, Qt::AlignRight);
        mainLayout->addWidget(transformationsCheckBox, 7, 2, Qt::AlignRight);
        setLayout(mainLayout);

        shapeChanged();
        penChanged();
        brushChanged();
        antialiasingCheckBox->setChecked(true);

        setWindowTitle(tr("Basic Drawing"));
}

const int IdRole = Qt::UserRole;

void Window::shapeChanged()
{
        RenderArea::Shape shape = RenderArea::Shape(shapeComboBox->itemData(
                                                                     shapeComboBox->currentIndex(), IdRole)
                                                        .toInt());
        renderArea->setShape(shape);
}

void Window::penChanged()
{
        int width = penWidthSpinBox->value();
        Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(
                                                              penStyleComboBox->currentIndex(), IdRole)
                                              .toInt());
        Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData(
                                                                penCapComboBox->currentIndex(), IdRole)
                                                  .toInt());
        Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(
                                                                    penJoinComboBox->currentIndex(), IdRole)
                                                     .toInt());

        renderArea->setPen(QPen(Qt::blue, width, style, cap, join));
}

void Window::brushChanged()
{
        Qt::BrushStyle style = Qt::BrushStyle(brushStyleComboBox->itemData(
                                                                    brushStyleComboBox->currentIndex(), IdRole)
                                                  .toInt());
        if (style == Qt::LinearGradientPattern)
        {
                QLinearGradient linearGradient(0, 0, 100, 100);
                linearGradient.setColorAt(0.0, Qt::white);
                linearGradient.setColorAt(0.2, Qt::green);
                linearGradient.setColorAt(1.0, Qt::black);
                renderArea->setBrush(linearGradient);
        }
        else if (style == Qt::RadialGradientPattern)
        {
                QRadialGradient radialGradient(50, 50, 50, 70, 70);
                radialGradient.setColorAt(0.0, Qt::white);
                radialGradient.setColorAt(0.2, Qt::green);
                radialGradient.setColorAt(1.0, Qt::black);
                renderArea->setBrush(radialGradient);
        }
        else if (style == Qt::ConicalGradientPattern)
        {
                QConicalGradient conicalGradient(50, 50, 150);
                conicalGradient.setColorAt(0.0, Qt::white);
                conicalGradient.setColorAt(0.2, Qt::green);
                conicalGradient.setColorAt(1.0, Qt::black);
                renderArea->setBrush(conicalGradient);
        }
        else
        {
                renderArea->setBrush(QBrush(Qt::green, style));
        }
}