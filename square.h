#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square: public Shape
{
public:

    /**
     * @brief Square()
     * default constructor
     */
    Square();

    /**
     * @brief Square()
     * paramaterized constructor
     */
    Square(const QColor &bColor, const QColor &color, const PenStyle &Pstyle, const PenCapStyle &PCstyle, const PenJoinStyle &PJstyle, const BrushStyle &Bstyle, int width, int id, int w, int x, int y);

    /**
     * @brief ~Square()
     * destructor
     */
    ~Square();

    /**
     * @brief setCenter()
     * sets the center of the shape
     */
    void setCenter(int x, int y);

    /**
     * @brief setWidth()
     * sets the width of the shape
     */
    void setWidth(int w){width = w;};

    /**
    * @brief getWidth()
    * gets the width of the shape
    */
    int getWidth(){return width;};


    /**
     * @brief draw()
     * draws the shape to the canvas
     */
    virtual void draw(QPaintDevice* device);

    /**
     * @brief move()
     * moves the shape on the canvas
     */
    virtual void move(int x, int y);


    /**
     * @brief getStart()
     * gets the starting point
     */
    QPoint getStart(){return startPoint;};

    Square &operator=(const Square &src);

private:
    QPoint startPoint;
    int width;
};

#endif // SQUARE_H
