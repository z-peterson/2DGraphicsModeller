#include "contactpage.h"
#include "ui_contactpage.h"
#include <QDebug>
#include <iostream>
#include <fstream>

using namespace std;

contactPage::contactPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contactPage)
{
    ui->setupUi(this);

    QPixmap pix(":/image/src/img/BackLeftBotnet.jpg");
    ui->label->setPixmap(pix);

    ui->linkLabel->setText("<a href=\"https://github.com/rizzi-trevor/CS1C-2DGraphicsModeler\">Click Here!</a>");
    ui->linkLabel->setTextFormat(Qt::RichText);
    ui->linkLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->linkLabel->setOpenExternalLinks(true);
}

contactPage::~contactPage()
{
    delete ui;
}

void contactPage::onCancelClick()
{
    this->hide();

}

void contactPage::onConfrimClick()
{
    QString text = ui->inputTestimonial->toPlainText();

    ofstream outFile;

    outFile.open("C:/Users/Trevor Rizzi/Desktop/CS1C-2D/testimony.txt", ios::app);

    outFile << "User Entry: \n";
    outFile << text.toStdString() << "\n\n";

    this->hide();

}
