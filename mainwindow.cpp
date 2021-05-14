#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/image/src/img/BackLeftBotnet2.jpg");
    ui->label->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onLoginClick()
{
    QString user = this->ui->usernameLine->text();
    QString pass = this->ui->passwordLine->text();


    if(user == "admin1" && pass == "admin1")// login for the admin
    {
        this->ui->warningLabel->setText("");
        this->hide();
        view = new viewer(this, true);
        view->show();

    }
    else
    {
        this->ui->warningLabel->setText("Username or Password is incorrect!");
    }


}

void MainWindow::onClearClick()
{
    this->ui->warningLabel->setText("");
    this->ui->usernameLine->setText("");
    this->ui->passwordLine->setText("");

}

void MainWindow::onModelerClick()
{
    this->ui->warningLabel->setText("");
    this->hide();
    view = new viewer(this, false);
    view->show();
}
