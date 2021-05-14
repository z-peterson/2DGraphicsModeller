#ifndef POLYLINE_H
#define POLYLINE_H

#include "shape.h"
#include "vector.h"

/**
 * @brief Polyline
 *
 */
class Polyline: public Shape
{
public:
    /**
     * @brief Polyline()
     * constructor
     */
    Polyline();

    /**
     * @brief Polyline()
     * constructor with parameters
     */
    Polyline(const QColor &bColor, const QColor &color, const PenStyle &Pstyle, const PenCapStyle &PCstyle, const PenJoinStyle &PJstyle, const BrushStyle &Bstyle, int width, int id, vector<QPoint> Qpoints);

    /**
     * @brief ~Polyline()
     * destructor
     */
    ~Polyline();

    /**
     * @brief addPoint()
     * adds point to list of points for polyline
     */
    void addPoint(int x, int y);

    /**
     * @brief draw()
     * draws shape to canvas
     */
    virtual void draw(QPaintDevice* device);

    /**
     * @brief move()
     * moves shape on canvas
     */
    virtual void move(int x, int y);

    Polyline &operator=(const Polyline &src);

    /**
     * @brief returnPoints()
     *  returns list of points
     */
    vector<QPoint> returnPoints();

private:
    QPoint * pointList;
    int pointCount;
};

#endif // POLYLINE_H
