#ifndef SHAPE_H
#define SHAPE_H

#include <QBrush>
#include <QPainter>
#include <QPen>
#include <QPoint>
#include <QFont>
#include "math.h"

using namespace Qt;
using namespace std;


/**
 * @brief Shape
 * shape class
 * all of these public or protected
 * methods are inherited
 * in the shape hierarchy
 */
class Shape
{
public:

    /**
     * @brief Shape()
     * constructor
     */
    Shape();

    /**
     * @brief Shape()
     * Parameterized constructor
     */
    Shape(const QColor &bColor, const QColor &color, const PenStyle &Pstyle, const PenCapStyle &PCstyle, const PenJoinStyle &PJstyle, const BrushStyle &Bstyle, int width, int id);

    /**
     * @brief getShapeID()
     * returns the shapeid
     */
    int getShapeID() const {return shapeID;};

    /**
     * @brief setPenWidth()
     * returns the width of the pen
     */
    void setPenWidth(int width);

    /**
     * @brief setPenColor()
     * sets the pen color of a shape
     */
    void setPenColor(const QColor &color);

    /**
     * @brief setPenStyle()
     * set the style of a pen
     */
    void setPenStyle(const PenStyle &style);

    /**
     * @brief setPenCapStyle()
     * set the pen cap style
     */
    void setPenCapStyle(const PenCapStyle &style);
    /**
     * @brief setPenJoinStyle()
     * set the pen join style
     */
    void setPenJoinStyle(const PenJoinStyle &style);

    /**
     * @brief setBrushColor()
     * set the brush color
     */
    void setBrushColor(const QColor &color);

    /**
     * @brief setBrushStyle()
     * set the brush sttyle
     */
    void setBrushStyle(const BrushStyle &style);

    /**
     * @brief getPen()
     * return the pen
     */
    QPen getPen(){return pen;};

    /**
     * @brief getBrush()
     * return the brush
     */
    QBrush getBrush(){return brush;};

    /**
     * @brief getArea()
     * pure virtual
     * gets the area of a shape
     */
    virtual int getArea(){return 0;};

    /**
     * @brief getPerim()
     * pure virtual
     * gets the perimeter of a
     * shape
     */
    virtual int getPerim(){return 0;};

    /**
     * @brief getPos()
     *gets the position of a shape
     *
     */
    virtual QPoint getPos(){return {0,0};};

    /**
     * @brief draw()
     * draws the shape to the canvas
     */
    virtual void draw(QPaintDevice* device);

    /**
     * @brief move()
     * moves the shape on the canvas
     */
   virtual void move(int x1, int x2);

    /**
     * @brief getShapeName()
     *  returns the name of a shape
     */
    QString getShapeName() const{return shapeName;};

    QPen pen;

    QBrush brush;

    QPainter painter;


protected:
    QString shapeName;
    int shapeID;

private:

};

#endif // SHAPE_H
