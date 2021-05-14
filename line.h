#ifndef LINE_H
#define LINE_H

#include "shape.h"

/**
 * @brief Line
 * Line class inherited from shape
 */
class Line: public Shape
{
public:
    /**
     * @brief Line()
     *
     */
    Line(const QColor &color, const PenStyle &Pstyle, const PenCapStyle &PCstyle, const PenJoinStyle &PJstyle, const BrushStyle &Bstyle, int width, int id, QPoint s, QPoint e);

    /**
     * @brief ~Line()
     * destructor
     *
     */
    ~Line();

    /**
     * @brief draw()
     * draws shape to canvas
     */
    virtual void draw(QPaintDevice* device);

    /**
     * @brief move()
     * moves location of shape on canvas
     */
    virtual void move(int x, int y);

    /**
     * @brief setStart()
     * sets start point of line
     */
    void setStart(int x, int y);

    /**
     * @brief setEnd()
     * sets end point of line
     */
    void setEnd(int x, int y);

     /**
     * @brief getEnd()
     * returns the end point of line
     */
    QPoint getEnd(){return end;};

    /**
     * @brief getStart()
     * returns the start point of line
     */
    QPoint getStart(){return start;};

    Line &operator=(const Line &src);


private:
    QPoint start;
    QPoint end;
};

#endif // LINE_H
