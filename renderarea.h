#ifndef RENDERAREA_H
#define RENDERAREA_H

#include "shape.h"
#include "vector.h"
#include "fileparser.h"
#include <QDebug>
#include "QDebug"

#include <QWidget>


/**
 * @brief RenderArea
 *  inherits from qwidget
 *  this class is used to add new functionality
 *  to a qtgraphics view. It implements the
 * draw canvas
 *
 */
class RenderArea : public QWidget
{
        Q_OBJECT
public:
    /**
     * @brief RenderArea()
     * explicit ui constructor
     */
    explicit RenderArea(QWidget *parent = 0);

    /**
     * @brief addShape()
     * add shape to the canvas
     */
    void addShape(Shape* addShape);

    /**
     * @brief moveShape()
     * move shape on the canvas
     */
    void  moveShape(int index, int x, int y);

    /**
     * @brief removeShape()
     * remove shape from the canvas
     */
    void removeShape(int index);

    /**
     * @brief returnShapeList()
     * return the list of shapes on the canvas
     */
    myVec::vector<Shape*> returnShapeList();

    /**
     * @brief listSize()
     * return the size of the list
     */
    int listSize();

    /**
     * @brief shapeIdAtIndex()
     * return the shape ID at any given index
     */
    int shapeIdAtIndex(int index);

    /**
     * @brief shapeIdAtEnd()
     * returns the shapeID at the
     * very end of the vector
     */
    int shapeIdAtEnd();


    /**
     * @brief shapeAtID()
     *  returns a point to shape
     *  with any matching id
     *
     */
    Shape *shapeAtID(int ID);

    /**
     * @brief setShape()
     *  edits a shape
     */
    void setShape(Shape &src);

protected:

    /**
     * @brief paintEvent()
     *  paints the shapelist to the canvas
     * This uses the draw functions implemented
     * in every shape class
     */
    void paintEvent(QPaintEvent *event) override;

private:

    myVec::vector<Shape*> shapeList = ParseFile(0);

};

#endif // RENDERAREA_H
