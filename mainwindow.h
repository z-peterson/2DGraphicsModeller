#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "viewer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief getStart()
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:

    /**
     * @brief onLoginClick()
     * closes login window opens up editor
     */
    void onLoginClick();

    /**
     * @brief onClearClick()
     * clears the user and pass
     * forms
     */
    void onClearClick();

    /**
     * @brief onModelerClick()
     * loads the 2d modeler
     */
    void onModelerClick();

public:
    /**
     * @brief MainWindow()
     *main window constructor
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief MainWindow()
     * destructor
     */
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    viewer *view;
};
#endif // MAINWINDOW_H
