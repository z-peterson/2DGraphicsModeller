#include "viewer.h"
#include "ui_viewer.h"
#include "confirmpage.h"
#include "mainwindow.h"

int shapeID::I_D = 0;
int properID::UNIQUE_ID = 0;

viewer::viewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewer)
{
    ui->setupUi(this);

}

viewer::viewer(QWidget *parent, bool admin)
    :QMainWindow(parent), ui(new Ui::viewer)
{
    if(admin == true)
    {
        ui->setupUi(this);
        updateScreen();
        this->setWindowTitle("2D-Editor [Admin]");

    }
    else
    {
        ui->setupUi(this);
        ui->lineButton->setEnabled(false);
        ui->polylineButton->setEnabled(false);
        ui->polygonButton->setEnabled(false);
        ui->squareButton->setEnabled(false);
        ui->rectangleButton->setEnabled(false);
        ui->ellipsebutton->setEnabled(false);
        ui->circleButton->setEnabled(false);
        ui->textButton->setEnabled(false);
        ui->removeButton->setEnabled(false);
        ui->editButton->setEnabled(false);
        ui->xBox->setEnabled(false);
        ui->yBox->setEnabled(false);
        ui->moveButton->setEnabled(false);
        this->setWindowTitle("2D-Editor [Guest]");

        ui->logout->setText("Login");

        ui->adminLabel->setText("ADMIN ONLY");
        updateScreen();

        //ui->canvas->moveShape();
    }

}

viewer::~viewer()
{
    delete ui;
}

void viewer::onAddLine()
{
    shapeID::I_D = 1;
    properID::UNIQUE_ID = ui->canvas->shapeIdAtEnd() + 1;
    confirmpage confirm;
    bool check = false;

    confirm.setModal(true);
    confirm.exec();
    check = confirm.getData();

    if(check == true)
    {
        ui->canvas->addShape(confirm.myLine);
    }

    updateScreen();

}

void viewer::onAddPolyline()
{
    shapeID::I_D = 2;
    properID::UNIQUE_ID = ui->canvas->shapeIdAtEnd() + 1;
    confirmpage confirm;
    bool check = false;

    confirm.setModal(true);
    confirm.exec();
    check = confirm.getData();

    if(check == true)
    {
        ui->canvas->addShape(confirm.myPolyline);
    }

    updateScreen();
}

void viewer::onAddPolygone()
{
    shapeID::I_D = 3;
    properID::UNIQUE_ID = ui->canvas->shapeIdAtEnd() + 1;
    confirmpage confirm;
    bool check = false;

    confirm.setModal(true);
    confirm.exec();
    check = confirm.getData();

    if(check == true)
    {
        ui->canvas->addShape(confirm.myPolygon);
    }

    updateScreen();
}

void viewer::onAddRectangle()
{
    shapeID::I_D = 4;
    properID::UNIQUE_ID = ui->canvas->shapeIdAtEnd() + 1;
    confirmpage confirm;
    bool check = false;

    confirm.setModal(true);
    confirm.exec();
    check = confirm.getData();

    if(check == true)
    {
        ui->canvas->addShape(confirm.myRectangle);
    }

    updateScreen();
}

void viewer::onAddSquare()
{
    shapeID::I_D = 5;
    properID::UNIQUE_ID = ui->canvas->shapeIdAtEnd() + 1;
    confirmpage confirm;
    bool check = false;

    confirm.setModal(true);
    confirm.exec();
    check = confirm.getData();

    if(check == true)
    {
        ui->canvas->addShape(confirm.mySquare);
    }

    updateScreen();
}

void viewer::onAddEllipse()
{
    shapeID::I_D = 6;
    properID::UNIQUE_ID = ui->canvas->shapeIdAtEnd() + 1;
    confirmpage confirm;
    bool check = false;

    confirm.setModal(true);
    confirm.exec();
    check = confirm.getData();

    if(check == true)
    {
        ui->canvas->addShape(confirm.myEllipse);
    }

    updateScreen();
}

void viewer::onAddCircle()
{
    shapeID::I_D = 7;
    properID::UNIQUE_ID = ui->canvas->shapeIdAtEnd() + 1;
    confirmpage confirm;
    bool check = false;

    confirm.setModal(true);
    confirm.exec();
    check = confirm.getData();

    if(check == true)
    {
        ui->canvas->addShape(confirm.myCircle);
    }

    updateScreen();
}

void viewer::onAddText()
{
    shapeID::I_D = 8;
    properID::UNIQUE_ID = ui->canvas->shapeIdAtEnd() + 1;
    confirmpage confirm;
    bool check = false;

    confirm.setModal(true);
    confirm.exec();
    check = confirm.getData();

    if(check == true)
    {
        ui->canvas->addShape(confirm.myText);
    }

    updateScreen();

}

void viewer::onLogout()
{
    ofstream outFile;

    outFile.open("C:/Users/Trevor Rizzi/Desktop/CS1C-2D/shapes.txt");
    this->hide();

    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();

    myVec::vector<Shape*> vec = ui->canvas->returnShapeList();

    outFile << vec;

    outFile.close();


}

void viewer::displayVector()
{
    myVec::vector <Shape*> display = ui->canvas->returnShapeList(); // copy constructor

    ui->shapeTable->setRowCount(display.size());
    ui->shapeTable->setColumnCount(2);

    QTableWidgetItem *header1 = new QTableWidgetItem();
    header1->setText("Shape");
    ui->shapeTable->setHorizontalHeaderItem(0,header1);

    QTableWidgetItem *header2 = new QTableWidgetItem();
    header2->setText("ID");
    ui->shapeTable->setHorizontalHeaderItem(1,header2);

    for(int i = 0; i < display.size(); i ++)
    {
        int id = display[i]->getShapeID();

        QString name = display[i]->getShapeName();

        QTableWidgetItem *newItemOne = new QTableWidgetItem(QString::number(id));
        QTableWidgetItem *newItemTwo = new QTableWidgetItem(name);

        qDebug() << id;

        ui->shapeTable->setItem(i, 1, newItemOne);
        ui->shapeTable->setItem(i - 1, 2, newItemTwo);

    }


}

void viewer::updateScreen()
{
    ui->canvas->update();
    displayVector();
}

void viewer::removeShape()
{
    QTableWidgetItem *item;

    int row = ui->shapeTable->currentRow(); // gets the entire row

    item = ui->shapeTable->item(row, 1); // row, col;

    if(item == NULL)
    {
        ui->removeLabel->setText("Please select a shape from above!");
    }
    else
    {
        ui->removeLabel->setText("");
        int delItem = item->text().toInt();
        ui->canvas->removeShape(delItem);
    }


    updateScreen();

}

void viewer::onRemoveClick()
{
    removeShape();
}


void viewer::onEditClick()
{
    QTableWidgetItem *item;

    int row = ui->shapeTable->currentRow(); // gets the entire row

    item = ui->shapeTable->item(row, 1); // row, col;

    if(item == NULL)
    {
        ui->removeLabel->setText("Please select a shape from above!");
    }
    else
    {
        ui->removeLabel->setText("");
        int delItem = item->text().toInt();
        Shape * shapePtr = ui->canvas->shapeAtID(delItem);
        Shape * confirmPtr;
        QString name = shapePtr->getShapeName();
        int editID = shapePtr->getShapeID();

        if(name == "Line")
        {
            shapeID::I_D = 1;
            properID::UNIQUE_ID = editID; // we run into an issue here if we try and edit shapes above index 8!!

            confirmpage confirm;
            bool check = false;

            confirm.setModal(true);
            confirm.exec();
            check = confirm.getData();

            confirmPtr = confirm.myLine;

            if(check == true)
            {
                ui->canvas->setShape(*confirmPtr);
            }

        }
        else if(name == "Polyline")
        {
            shapeID::I_D = 2;
            properID::UNIQUE_ID = editID;

            confirmpage confirm;
            bool check = false;

            confirm.setModal(true);
            confirm.exec();
            check = confirm.getData();

            confirmPtr = confirm.myPolyline;

            if(check == true)
            {
                ui->canvas->setShape(*confirmPtr);
            }
        }
        else if(name == "Polygon")
        {
            shapeID::I_D = 3;
            properID::UNIQUE_ID = editID;

            confirmpage confirm;
            bool check = false;

            confirm.setModal(true);
            confirm.exec();
            check = confirm.getData();

            confirmPtr = confirm.myPolygon;

            if(check == true)
            {
                ui->canvas->setShape(*confirmPtr);
            }
        }
        else if(name == "Rectangle")
        {
            shapeID::I_D = 4;
            properID::UNIQUE_ID = editID;

            confirmpage confirm;
            bool check = false;

            confirm.setModal(true);
            confirm.exec();
            check = confirm.getData();

            confirmPtr = confirm.myRectangle;

            if(check == true)
            {
                ui->canvas->setShape(*confirmPtr);
            }
        }
        else if(name == "Square")
        {
            shapeID::I_D = 5;
            properID::UNIQUE_ID = editID;

            confirmpage confirm;
            bool check = false;

            confirm.setModal(true);
            confirm.exec();
            check = confirm.getData();

            confirmPtr = confirm.mySquare;

            if(check == true)
            {
                ui->canvas->setShape(*confirmPtr);
            }
        }
        else if(name == "Ellipse")
        {
            shapeID::I_D = 6;
            properID::UNIQUE_ID = editID;

            confirmpage confirm;
            bool check = false;

            confirm.setModal(true);
            confirm.exec();
            check = confirm.getData();

            confirmPtr = confirm.myEllipse;

            if(check == true)
            {
                ui->canvas->setShape(*confirmPtr);
            }
        }
        else if(name == "Circle")
        {
            shapeID::I_D = 7;
            properID::UNIQUE_ID = editID;

            confirmpage confirm;
            bool check = false;

            confirm.setModal(true);
            confirm.exec();
            check = confirm.getData();

            confirmPtr = confirm.myCircle;

            if(check == true)
            {
                ui->canvas->setShape(*confirmPtr);
            }
        }else if("Text")
        {

        }

    }


    updateScreen();


}

void viewer::onContactClick()
{
    contact = new contactPage;

    contact->show();
}

void viewer::onTestimonialClick()
{
    testimony = new testimobialView;

    testimony->show();

}

void viewer::moveSelectedShape()
{
    QTableWidgetItem *item;
    int x = ui->xBox->value();
    int y = ui->yBox->value();

    int row = ui->shapeTable->currentRow(); // gets the entire row

    item = ui->shapeTable->item(row, 1); // row, col;

    if(item == NULL)
    {
        ui->removeLabel->setText("Please select a shape from above!");
    }
    else
    {
        ui->removeLabel->setText("");
        int moveItem = item->text().toInt();
        ui->canvas->moveShape(moveItem, x, y);
    }


    updateScreen();

}

void viewer::onMoveClick()
{
    moveSelectedShape();

}

