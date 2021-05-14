#include "line.h"
#include <QtDebug>

Line::Line(const QColor &color, const PenStyle &Pstyle, const PenCapStyle &PCstyle, const PenJoinStyle &PJstyle, const BrushStyle &Bstyle, int width, int id, QPoint s, QPoint e)
     :Shape(white, color, Pstyle, PCstyle, PJstyle, Bstyle, width, id) // that white might be an issue idk
{
    start = s;
    end = e;

    shapeName = "Line";

}

Line::~Line(){}

void Line::draw(QPaintDevice* device)
{
    painter.begin(device);
    painter.drawText(start - QPoint{10 , 15}, QString("ID: %1").arg(getShapeID()));
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawLine(start, end);
    painter.end();

}

void Line::move(int x, int y)
{
    QPoint sPoint = getStart();
    int offX = sPoint.x();
    int offY = sPoint.y();

    QPoint ePoint = getEnd();
    int endX = ePoint.x();
    int endY = ePoint.y();

    setStart(x,y);
    setEnd(endX + offX, endY + offY);


}

void Line::setStart(int x, int y)
{
    start.setX(x);
    start.setY(y);

}

void Line::setEnd(int x, int y)
{
    end.setX(x);
    end.setY(y);

}

Line& Line::operator=(const Line &src)
{
    this->pen = src.pen;
    this->brush = src.brush;
    this->shapeID = src.getShapeID();
    this->shapeName = src.getShapeName();
    this->start = src.start;
    this->end = src.end;

    return *this;
}
