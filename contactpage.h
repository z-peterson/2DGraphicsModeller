#ifndef CONTACTPAGE_H
#define CONTACTPAGE_H

#include <QDialog>
#include <fstream>

namespace Ui {
class contactPage;
}


/**
 * @brief contactPage
 * Ui page for submitting testimonials
 */
class contactPage : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief contactPage()
     * explicit constructor
     */
    explicit contactPage(QWidget *parent = nullptr);
    /**
     * @brief contactPage()
     * destructor
     */
    ~contactPage();

public slots:
    /**
     * @brief onCancelClick()
     * closes the window, and does NOT submit
     * a testimonial
     */
    void onCancelClick();
    /**
     * @brief onConfrimClick()
     * Confirms the addition of a new
     * testimonial and closes the window
     */
    void onConfrimClick();

private:
    Ui::contactPage *ui;
};

#endif // CONTACTPAGE_H
