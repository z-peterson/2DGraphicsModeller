#ifndef TESTIMOBIALVIEW_H
#define TESTIMOBIALVIEW_H

#include <QDialog>
#include <iostream>
#include <fstream>
using namespace std;


/**
 * @brief testimobialView()
 * Ui window to display user testimonials
 */
namespace Ui {
class testimobialView;
}

class testimobialView : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief testimobialView()
     * construct the window
     */
    explicit testimobialView(QWidget *parent = nullptr);

    /**
     * @brief testimobialView()
     * destruct the window
     */
    ~testimobialView();

public slots:

    /**
     * @brief onCloseClick()
     * close the testimonial view
     */
    void onCloseClick();

private:
    Ui::testimobialView *ui;
};

#endif // TESTIMOBIALVIEW_H
