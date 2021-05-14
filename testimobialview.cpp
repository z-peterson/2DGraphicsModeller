#include "testimobialview.h"
#include "ui_testimobialview.h"
#include <QDebug>

testimobialView::testimobialView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testimobialView)
{
    ui->setupUi(this);

    string text;
    ifstream inFile;

    inFile.open("C:/Users/Trevor Rizzi/Desktop/CS1C-2D/testimony.txt");

    while(inFile)
    {
        getline(inFile, text);
        qDebug() << QString::fromStdString(text);
        ui->output->append(QString::fromStdString(text));


    }

    inFile.close();
}

testimobialView::~testimobialView()
{
    delete ui;


}


void testimobialView::onCloseClick()
{
    this->hide();
}
