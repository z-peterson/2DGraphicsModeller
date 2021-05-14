#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle: public Shape
{
public:

    /**
     * @brief Rectangle()
     * constructor
     */
    Rectangle();

    /**
     * @brief Rectangle()
     * constructor with parameters
     */
    Rectangle(const QColor &bColor, const QColor &color, const PenStyle &Pstyle, const PenCapStyle &PCstyle, const PenJoinStyle &PJstyle, const BrushStyle &Bstyle, int width, int id, int l, int w, int x, int y);

    /**
     * @brief Rectangle()
     * destructor
     */
    ~Rectangle();

    /**
     * @brief setCenter()
     * set center of shape
     */
    void setCenter(int x, int y);

    /**
     * @brief setLength()
     * set length of shape
     */
    void setLength(int l){length = l;};

    /**
     * @brief setWidth()
     * set width of shape
     */
    void setWidth(int w){width = w;};

    /**
     * @brief getWidth()
     * get width of shape
     */
    int getWidth(){return width;};

    /**
     * @brief getLength()
     * get length of shape
     */
    int getLength(){return length;};

    /**
     * @brief getStart()
     * get starting point of shape
     */
    QPoint getStart(){return startPoint;};

    /**
     * @brief draw()
     * draw shape to canvas
     */
    virtual void draw(QPaintDevice* device);

    /**
     * @brief move()
     * move shape on canvas
     */
    virtual void move(int x, int y);

    Rectangle &operator=(const Rectangle &src);

private:
    QPoint startPoint;
    int length;
    int width;
};

#endif // RECTANGLE_H
