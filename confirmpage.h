#ifndef CONFIRMPAGE_H
#define CONFIRMPAGE_H

#include <QDialog>
#include "QDebug"

#include "fileparser.h"

namespace shapeID
{
    extern int I_D;
}

namespace properID
{
    extern int UNIQUE_ID;
}


/**
 * @brief confirmpage()
 * ui page for adding and editing shapes
 *
 */
namespace Ui {
class confirmpage;
}

class confirmpage : public QDialog
{
    Q_OBJECT
public:

    /**
     * @brief confirmpage()
     *  explicit default constructor
     */
    explicit confirmpage(QWidget *parent = nullptr);

    /**
     * @brief ~confirmpage()
     * default destructor
     */
    ~confirmpage();

    /**
     * @brief confirmpage()
     * alternate class constructor
     *
     */
    confirmpage(QWidget *parent, bool &returnAnswer);

    //! gets data from confirm page
    bool getData();

    Line *myLine;
    Polyline *myPolyline;
    Polygon *myPolygon;
    Rectangle *myRectangle;
    Square *mySquare;
    Circle *myCircle;
    Ellipse *myEllipse;
    Text *myText;


private slots:

    /**
     * @brief onCancelClick()
     * closes the window, and does NOT add a shape
     * to the canvas
     *
     */
    void onCancelClick();

    /**
     * @brief onConfirmClick()
     * closes the window and DOES add a shape to the canvas
     */
    void onConfirmClick();


    /**
     * @brief onAddClick()
     * adds QPoints to a list of Qpoints
     *
     * This is meant for any shape that has a starting point and
     * possibly others
     */
    void onAddClick();

private:

    int maxPoints;  ///< maximum amount of points allowed for a given shape
    int pointCount; ///< Number of points already consumed
    int width;      ///< width

    Ui::confirmpage *ui;

    bool answer = false; ///< cancel button returns false

    vector<QPoint> points; ///< stores shape points

    string color, style, cap, join, brushStyle, brushColor;

    QColor qtColor, qtBColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    BrushStyle qtBrush;
};


#endif // CONFIRMPAGE_H
