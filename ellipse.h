#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"

/**
 * @brief Ellipse()
 * ellipse shape inherited from shape class
 * custom shape for low level qpainter
 */
class Ellipse: public Shape
{
public:

    /**
     * @brief Ellipse()
     * Alternate construct with parameters
     */
    Ellipse(const QColor &bColor, const QColor &color, const PenStyle &Pstyle, const PenCapStyle &PCstyle, const PenJoinStyle &PJstyle, const BrushStyle &Bstyle, int width, int id, int a, int b, int x, int y);

    /**
     * @brief ~Ellipse()
     * destructs ellipse class
     */
    ~Ellipse();

    /**
     * @brief draw()
     * draws shape to canvas
     */
    virtual void draw(QPaintDevice* device);

    /**
     * @brief move()
     * moves position of shape
     * on canvas
     */
    virtual void move(int x, int y);

    /**
     * @brief setCenter()
     * sets center of shape
     */
    void setCenter(int x, int y);

    /**
     * @brief setA()
     * sets the A length of
     * an ellipse
     */
    void setA(int a);

    /**
     * @brief setB()
     * sets the B length of an ellipse
     */
    void setB(int b);

    /**
     * @brief getArea()
     * gets the area of the ellipse
     */
    virtual int getArea(){return (M_PI * a * b);};

    /**
     * @brief getA()
     * gets the A length of
     * ellipse
     */
    int getA(){return a;};

    /**
     * @brief getB()
     * gets the B length
     * of ellipse
     */
    int getB(){return b;};


    /**
     * @brief getStart()
     * gets the starting point of ellipse
     */
    QPoint getStart(){return startPoint;};

    Ellipse &operator=(const Ellipse &src);


private:
    QPoint startPoint;
    int a;
    int b;
};

#endif // ELLIPSE_H
