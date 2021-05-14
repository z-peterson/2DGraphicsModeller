#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

/**
 * @brief Circle
 * Circle class inherited from shape
 * creates custom shape for low level qPainter
 *
 */

class Circle: public Shape
{
public:

    /**
     * @brief Circle()
     * Overloaded constructor
     */
    Circle(const QColor &bColor, const QColor &color, const PenStyle &Pstyle, const PenCapStyle &PCstyle, const PenJoinStyle &PJstyle, const BrushStyle &Bstyle, int width, int id, int radius, int x, int y);

    /**
     * @brief Circle()
     * Destructor
     */
    ~Circle();


    /**
     * @brief draw()
     * Uses the low level qpaint to paint custom shapes
     */
    virtual void draw(QPaintDevice* device);

    /**
     * @brief move()
     * Moves the loacation of the shape
     */
    virtual void move(int x, int y);

    /**
     * @brief setCenter()
     * Sets the center of the shape
     */
    void setCenter(int x, int y);

    /**
     * @brief setRadius()
     * Sets the radius of the shape
     */
    void setRadius(int r);

    /**
     * @brief getArea()
     * returns the area of the shape
     */
    virtual int getArea(){return (int)(M_PI * (pow(radius,2)));};

    /**
     * @brief getPerim()
     * returns the perimeter of the shape
     */
    virtual int getPerim(){return (int)(2 * M_PI * radius);};

    /**
     * @brief getRadius()
     * returns the radius of the shape
     */
    int getRadius(){return radius;};

    /**
     * @brief getStart()
     * returns, as a QPoint, the starting point of the shape
     */
    QPoint getStart(){return startPoint;};

    /**
     * @brief operator=()
     * overloaded assignment operator FOR circle assignment ONLY
     */
    Circle &operator=(const Circle &src);

private:
    QPoint startPoint;
    int radius;


};

#endif // CIRCLE_H
