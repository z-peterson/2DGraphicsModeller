#ifndef VIEWER_H
#define VIEWER_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <fstream>
#include "renderarea.h"
#include "circle.h"
#include "serializer.h"
#include "contactpage.h"
#include "testimobialview.h"


/**
 * @brief viewer()
 *  Ui main editor page
 * holds the canvas for
 * rendering shapes
 *
 */
namespace Ui {
class viewer;
}

class viewer : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief viewer()
     * explicit constructor
     */
    explicit viewer(QWidget *parent = nullptr);


    /**
     * @brief viewer()
     * constructor
     * takes parameter bool admin
     * to determine whether the user is
     * a guest or administrator
     */
    viewer(QWidget *parent, bool admin);

    /**
     * @brief ~viewer()
     * destructor
     */
    ~viewer();

    /**
     * @brief displayVector()
     * display the shape vector
     */
    void displayVector();

    /**
     * @brief updateScreen()
     * update the window
     */
    void updateScreen();

    /**
     * @brief removeShape()
     * remove a selected shape
     */
    void removeShape();

    /**
     * @brief moveSelectedShape()
     * move a selected shape
     */
    void moveSelectedShape();

public slots:

    /**
     * @brief onAddLine()
     * add line to canvas
     */
    void onAddLine();

    /**
     * @brief onAddPolyline()
     * add polyline to canvas
     */
    void onAddPolyline();

    /**
     * @brief onAddPolygone()
     * add polygon to canvas
     */
    void onAddPolygone();

    /**
     * @brief onAddRectangle()
     * add rectangle to canvas
     */
    void onAddRectangle();

    /**
     * @brief onAddSquare()
     * add squar eto canvas
     */
    void onAddSquare();

    /**
     * @brief onAddEllipse()
     * add ellipse to canvas
     */
    void onAddEllipse();

    /**
     * @brief onAddCircle()
     * add circle to canvas
     */
    void onAddCircle();

    /**
     * @brief onAddText()
     * add text to canvas
     */
    void onAddText();

    /**
     * @brief onLogout()
     * logout - closes
     * the editor window
     */
    void onLogout();

    /**
     * @brief onRemoveClick()
     * remove shape
     */
    void onRemoveClick();

    /**
     * @brief onEditClick()
     * edit shape
     */
    void onEditClick();

    /**
     * @brief onContactClick()
     * show contact page
     */
    void onContactClick();

    /**
     * @brief onTestimonialClick()
     * show testimonial page
     */
    void onTestimonialClick();

    /**
     * @brief onMoveClick()
     * move a shape
     */
    void onMoveClick();



private:
    Ui::viewer *ui;

    contactPage *contact;
    testimobialView *testimony;

};

#endif // VIEWER_H
