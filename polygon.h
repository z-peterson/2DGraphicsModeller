#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
#include "vector.h"

class Polygon: public Shape
{
public:

    /**
     * @brief Polygon()
     * default constructor
     */
    Polygon();

    /**
     * @brief Polygon()
     * alternate constructor
     * with parameters
     */
    Polygon(const QColor &bColor, const QColor &color, const PenStyle &Pstyle, const PenCapStyle &PCstyle, const PenJoinStyle &PJstyle, const BrushStyle &Bstyle, int width, int id, vector<QPoint> Qpoints);

    /**
     * @brief Polygon()
     * destructor
     */
    ~Polygon();


    /**
     * @brief addPoint()
     * adds point to pointlist
     */
    void addPoint(int x, int y);

    /**
     * @brief initializeList()
     * initializes point list
     */
    void initializeList();

    /**
     * @brief draw()
     * draws the shape to the canvas
     */
    virtual void draw(QPaintDevice* device);

    /**
     * @brief move()
     * moves the location of the shape
     * on the canvas
     */
    virtual void move(int x, int y);

    /**
     * @brief getPerimeter()
     * gets the perimeter of the shape
     */
    virtual int getPerimeter();

    /**
     * @brief getArea()
     * gets the area of the shape
     */
    virtual int getArea();

    /**
     * @brief returnPoints()
     * returns the vector of points that
     * any given polygon has
     */
    vector<QPoint> returnPoints(){return points;};

    Polygon &operator=(const Polygon &src);

private:
    QPoint *pointList;
    int pointCount;
    vector<QPoint> points;

};

#endif // POLYGON_H
