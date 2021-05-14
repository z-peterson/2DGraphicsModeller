#include "polygon.h"

Polygon::Polygon() : Shape()
{
    pointList = new QPoint[5];
    pointCount = 0;
}
Polygon::Polygon(const QColor &bColor, const QColor &color, const PenStyle &Pstyle, const PenCapStyle &PCstyle, const PenJoinStyle &PJstyle, const BrushStyle &Bstyle, int width, int id, vector<QPoint> Qpoints)
        :Shape(bColor, color, Pstyle, PCstyle, PJstyle, Bstyle, width, id)
{
    pointList = new QPoint[5]; // maybe change from 5??
    for(unsigned int i = 0; i < Qpoints.size(); i++)
    {
        pointList[i] = Qpoints[i];
    }

    points = Qpoints;

    pointCount = Qpoints.size();

    shapeName = "Polygon";

}

Polygon::~Polygon()
{
    delete [] pointList;
}

void Polygon::addPoint(int x, int y)
{
    pointList[pointCount].setX(x);
    pointList[pointCount].setY(y);
    pointCount++;
}

void Polygon::initializeList()
{
    for(int i = 0; i < pointCount; i++)
    {
            points[i].setX(pointList[i].rx());
            points[i].setY(pointList[i].ry());
    }
}

void Polygon::draw(QPaintDevice* device)
{
    painter.begin(device);
    painter.drawText(pointList[0] - QPoint{35 , 15}, QString("ID: %1").arg(getShapeID()));
    painter.setPen(getPen());
    painter.setBrush(brush);

    painter.drawPolygon(pointList, pointCount);
    painter.end();

}

void Polygon::move(int x, int y)
{
    int offsetX = x - pointList[0].x();
    int offsetY = y - pointList[0].y();

    for(int i = 0; i < pointCount; i++)
    {
        pointList[i].setX(pointList[i].x() + offsetX);
        pointList[i].setY(pointList[i].y() + offsetY);
    }
}

int Polygon::getPerimeter()
{
    int perimeter = 0;
    for(int i = 0; i < pointCount; i++)
    {
        perimeter += sqrt(pow(pointList[i + 1].x() - pointList[i].x(), 2) + pow(pointList[i + 1].y() - pointList[i].y(), 2));
        if(i == (pointCount - 1))
        {
            perimeter += sqrt(pow(pointList[0].x() - pointList[i].x(), 2) + pow(pointList[0].y() - pointList[i].y(), 2));
        }
    }
    return perimeter;
}

int Polygon::getArea()
{
    double area = 0.0;
    for(int i = 0; i < pointCount; i++)
    {
        area += ((pointList[i].x() * pointList[i + 1].y()) - (pointList[i].y() * pointList[i + 1].x()));
        if(i == (pointCount - 1))
        {
            area += ((pointList[i].x() * pointList[0].y()) - (pointList[i].y() * pointList[0].x()));
        }
     }
     return area;
}

Polygon& Polygon::operator=(const Polygon &src)
{
    this->pen = src.pen;
    this->brush = src.brush;
    this->shapeID = src.getShapeID();
    this->shapeName = src.getShapeName();
    this->pointCount = src.pointCount;


    pointList = new QPoint[5]; // maybe change from 5??
    for(int i = 0; i < src.pointCount; i++)
    {
        pointList[i] = src.pointList[i];
    }


    return *this;
}
