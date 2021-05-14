#include "rectangle.h"
#include <QDebug>

Rectangle::Rectangle()
          :Shape()
{

}

Rectangle::Rectangle(const QColor &bColor, const QColor &color, const PenStyle &Pstyle, const PenCapStyle &PCstyle, const PenJoinStyle &PJstyle, const BrushStyle &Bstyle, int width, int id, int l, int w, int x, int y)
          :Shape(bColor, color, Pstyle, PCstyle, PJstyle, Bstyle, width, id)
{

    startPoint.setX(x);
    startPoint.setY(y);
    this->width = w;
    length = l;

    shapeName = "Rectangle";

}

Rectangle::~Rectangle()
{

}


void Rectangle::draw(QPaintDevice* device) //needs change
{

    painter.begin(device);
    painter.drawText(startPoint - QPoint {0, 4}, QString("ID: %1").arg(getShapeID()));
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(startPoint.rx(), startPoint.ry(), width, length);

    painter.end();

}

void Rectangle::move(int x, int y)
{
    setCenter(x , y);
}

void Rectangle::setCenter(int x, int y)
{
    startPoint.setX(x);
    startPoint.setY(y);

}


Rectangle& Rectangle::operator=(const Rectangle &src)
{
    this->pen = src.pen;
    this->brush = src.brush;
    this->shapeID = src.getShapeID();
    this->shapeName = src.getShapeName();
    this->length = src.length;
    this->width = src.width;
    this->startPoint = src.startPoint;

    return *this;
}
