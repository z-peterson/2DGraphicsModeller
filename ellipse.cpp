#include "ellipse.h"

Ellipse::Ellipse(const QColor &bColor, const QColor &color, const PenStyle &Pstyle, const PenCapStyle &PCstyle, const PenJoinStyle &PJstyle, const BrushStyle &Bstyle, int width, int id, int a, int b, int x, int y)
        :Shape(bColor, color, Pstyle, PCstyle, PJstyle, Bstyle, width, id)
{
    setCenter(x, y);
    setA(a);
    setB(b);

    shapeName = "Ellipse";
}


void Ellipse::draw(QPaintDevice* device) //needs change
{
    painter.begin(device);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(startPoint.rx(), startPoint.ry(), a, b);
    painter.drawText(startPoint, QString("ID: %1").arg(getShapeID()));
    painter.end();

}


void Ellipse::move(int x, int y)
{
    setCenter(x , y);

}

void Ellipse::setCenter(int x, int y)
{
    startPoint.setX(x);
    startPoint.setY(y);
}

void Ellipse::setA(int a)
{
    this->a = a;
}

void Ellipse::setB(int b)
{
    this->b = b;
}

Ellipse& Ellipse::operator=(const Ellipse &src)
{
    this->pen = src.pen;
    this->brush = src.brush;
    this->shapeID = src.getShapeID();
    this->shapeName = src.getShapeName();
    this->a = src.a;
    this->b = src.b;
    this->startPoint = src.startPoint;

    return *this;
}
