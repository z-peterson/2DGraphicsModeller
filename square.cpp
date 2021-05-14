#include "square.h"

Square::Square()
          :Shape()
{

}

Square::Square(const QColor &bColor, const QColor &color, const PenStyle &Pstyle, const PenCapStyle &PCstyle, const PenJoinStyle &PJstyle, const BrushStyle &Bstyle, int width, int id, int w, int x, int y)
          :Shape(bColor, color, Pstyle, PCstyle, PJstyle, Bstyle, width, id)
{

    startPoint.setX(x);
    startPoint.setY(y);
    this->width = w;

    shapeName = "Square";

}

Square::~Square()
{

}


void Square::draw(QPaintDevice* device) //needs change
{
    painter.begin(device);
    painter.drawText(startPoint - QPoint {0, 4}, QString("ID: %1").arg(getShapeID()));
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(startPoint.rx(), startPoint.ry(), width, width);
    painter.end();

}

void Square::move(int x, int y)
{
    setCenter(x , y);
}

void Square::setCenter(int x, int y)
{
    startPoint.setX(x);
    startPoint.setY(y);

}

Square& Square::operator=(const Square &src)
{
    this->pen = src.pen;
    this->brush = src.brush;
    this->shapeID = src.getShapeID();
    this->shapeName = src.getShapeName();
    this->width = src.width;
    this->startPoint = src.startPoint;

    return *this;
}
