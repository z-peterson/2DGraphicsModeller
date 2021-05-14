#include "confirmpage.h"
#include "ui_confirmpage.h"

confirmpage::confirmpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::confirmpage)
{
    ui->setupUi(this);

    pointCount = 0;

    ui->textLabel->hide();
    ui->textLine->hide();

    //PEN COLORS
    ui->colorBox->addItem(" white");
    ui->colorBox->addItem(" black");
    ui->colorBox->addItem(" red");
    ui->colorBox->addItem(" green");
    ui->colorBox->addItem(" blue");
    ui->colorBox->addItem(" cyan");
    ui->colorBox->addItem(" magenta");
    ui->colorBox->addItem(" yellow");
    ui->colorBox->addItem(" gray");

    //BRUSH COLORS
    ui->colorBrushBox->addItem(" white");
    ui->colorBrushBox->addItem(" black");
    ui->colorBrushBox->addItem(" red");
    ui->colorBrushBox->addItem(" green");
    ui->colorBrushBox->addItem(" blue");
    ui->colorBrushBox->addItem(" cyan");
    ui->colorBrushBox->addItem(" magenta");
    ui->colorBrushBox->addItem(" yellow");
    ui->colorBrushBox->addItem(" gray");

    //PEN STYLES
    ui->styleBox->addItem(" NoPen");
    ui->styleBox->addItem(" SolidLine");
    ui->styleBox->addItem(" DashLine");
    ui->styleBox->addItem(" DotLine");
    ui->styleBox->addItem(" DashDotLine");
    ui->styleBox->addItem(" DashDotDotLine");

    //PEN CAP STYLES
    ui->capBox->addItem(" FlatCap");
    ui->capBox->addItem(" SquareCap");
    ui->capBox->addItem(" RoundCap ");

    //PEN JOIN STYLES
    ui->joinBox->addItem(" MiterJoin");
    ui->joinBox->addItem(" BevelJoin");
    ui->joinBox->addItem(" RoundJoin");

    //BRUSH STYLES
    ui->styleBrushBox->addItem(" SolidPattern");
    ui->styleBrushBox->addItem(" HorPattern");
    ui->styleBrushBox->addItem(" VerPattern");
    ui->styleBrushBox->addItem(" NoBrush");

    switch(shapeID::I_D)
    {
    case 1:
        maxPoints = 2;
        ui->colorBrushBox->hide();
        ui->brushLabel->hide();

        ui->styleBrushBox->hide();
        ui->styleBrushLabel->hide();

        ui->length->hide();
        ui->rectWidth->hide();
        ui->lBox->hide();
        ui->wBox->hide();

        ui->label->setText("Add Line");
        break;

    case 2:
        ui->label->setText("Add Polyline");

        ui->colorBrushBox->hide();
        ui->brushLabel->hide();

        ui->styleBrushBox->hide();
        ui->styleBrushLabel->hide();

        ui->length->hide();
        ui->rectWidth->hide();
        ui->lBox->hide();
        ui->wBox->hide();

        maxPoints = 10;
        break;

    case 3:
        ui->label->setText("Add Polygon");
        ui->length->hide();
        ui->rectWidth->hide();
        ui->lBox->hide();
        ui->wBox->hide();
        maxPoints = 10;
        break;

    case 4:
        maxPoints = 1;
        ui->centerLabel->setText("Set center point");
        ui->label->setText("Add Rectangle");

        break;

    case 5:
        maxPoints = 1;
        ui->centerLabel->setText("Set center point");
        ui->label->setText("Add Square");
        ui->lBox->hide();
        ui->length->hide();
        break;

    case 6:
        maxPoints = 1;
        ui->label->setText("Add Ellipse");
        ui->length->setText("B");
        ui->rectWidth->setText("A");
        break;

    case 7:
        maxPoints = 1;
        ui->label->setText("Add Circle");
        ui->rectWidth->setText("Radius");

        ui->length->hide();
        ui->lBox->hide();


        break;

    case 8:
        maxPoints = 1;


        ui->textLabel->show();
        ui->textLine->show();
        ui->label->setText("Add Text");
        ui->label_2->setText("Font Color");

        ui->colorBrushBox->clear();
        ui->brushLabel->setText("Font Weight");
        ui->colorBrushBox->addItem(" Thin");
        ui->colorBrushBox->addItem(" Light");
        ui->colorBrushBox->addItem(" Normal");
        ui->colorBrushBox->addItem(" Bold");

        ui->styleBox->clear();
        ui->label_4->setText("Font Style");
        ui->styleBox->addItem(" StyleNormal");
        ui->styleBox->addItem(" StyleItalic");
        ui->styleBox->addItem(" StyleOblique");

        ui->styleBrushBox->clear();
        ui->styleBrushLabel->setText("Text Font Family");
        ui->styleBrushBox->addItem(" Comic Sans MS");
        ui->styleBrushBox->addItem(" Courier");
        ui->styleBrushBox->addItem(" Helvetica");
        ui->styleBrushBox->addItem(" Times");

        ui->joinBox->clear();
        ui->label_6->setText("Text Alignment");
        ui->joinBox->addItem(" AlignLeft");
        ui->joinBox->addItem(" AlignRight");
        ui->joinBox->addItem(" AlignTop");
        ui->joinBox->addItem(" AlignBottom");
        ui->joinBox->addItem(" AlignCenter");

        ui->label_8->setText("Point Size");


        ui->label_7->hide();
        ui->capBox->hide();



        break;

    default:
        qDebug() << "ERROR loading UI";
        break;

    }

}

confirmpage::~confirmpage()
{
    delete ui;
}

bool confirmpage::getData()
{
    qDebug() << "getData()";
    return answer;
}

void confirmpage::onConfirmClick()
{
    int length;
    int rectWidth;
    int radius;


    switch(shapeID::I_D)
    {
    case 1:
        width = ui->widthBox->value();
        color = ui->colorBox->currentText().toStdString();
        qtColor = getColor(color);

        style = ui->styleBox->currentText().toStdString();
        qtStyle = getPenStyle(style);

        cap = ui->capBox->currentText().toStdString();
        qtCap = getPCStyle(cap);

        join = ui->joinBox->currentText().toStdString();
        qtJoin = getPJStyle(join);

        myLine = new Line(qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, properID::UNIQUE_ID, points[0], points[1]);

        break;

    case 2:
        width = ui->widthBox->value();
        color = ui->colorBox->currentText().toStdString();
        qtColor = getColor(color);

        style = ui->styleBox->currentText().toStdString();
        qtStyle = getPenStyle(style);

        cap = ui->capBox->currentText().toStdString();
        qtCap = getPCStyle(cap);

        join = ui->joinBox->currentText().toStdString();
        qtJoin = getPJStyle(join);

        myPolyline = new Polyline(white, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, properID::UNIQUE_ID, points);

        break;
    case 3:

        width = ui->widthBox->value();
        color = ui->colorBox->currentText().toStdString();
        qtColor = getColor(color);

        brushColor = ui->colorBrushBox->currentText().toStdString();
        qtBColor = getColor(brushColor);

        style = ui->styleBox->currentText().toStdString();
        qtStyle = getPenStyle(style);

        cap = ui->capBox->currentText().toStdString();
        qtCap = getPCStyle(cap);

        join = ui->joinBox->currentText().toStdString();
        qtJoin = getPJStyle(join);

        brushStyle = ui->styleBrushBox->currentText().toStdString();
        qtBrush = getBrushStyle(brushStyle);

        myPolygon = new Polygon(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, properID::UNIQUE_ID, points);

        break;
    case 4:
        width = ui->widthBox->value();
        color = ui->colorBox->currentText().toStdString();
        qtColor = getColor(color);

        brushColor = ui->colorBrushBox->currentText().toStdString();
        qtBColor = getColor(brushColor);

        style = ui->styleBox->currentText().toStdString();
        qtStyle = getPenStyle(style);

        cap = ui->capBox->currentText().toStdString();
        qtCap = getPCStyle(cap);

        join = ui->joinBox->currentText().toStdString();
        qtJoin = getPJStyle(join);

        brushStyle = ui->styleBrushBox->currentText().toStdString();
        qtBrush = getBrushStyle(brushStyle);

        length = ui->lBox->value();
        rectWidth = ui->wBox->value();

        myRectangle = new Rectangle(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, properID::UNIQUE_ID,length, rectWidth, points[0].rx(), points[0].ry());

        break;


    case 5:

        width = ui->widthBox->value();
        color = ui->colorBox->currentText().toStdString();
        qtColor = getColor(color);

        brushColor = ui->colorBrushBox->currentText().toStdString();
        qtBColor = getColor(brushColor);

        style = ui->styleBox->currentText().toStdString();
        qtStyle = getPenStyle(style);

        cap = ui->capBox->currentText().toStdString();
        qtCap = getPCStyle(cap);

        join = ui->joinBox->currentText().toStdString();
        qtJoin = getPJStyle(join);

        brushStyle = ui->styleBrushBox->currentText().toStdString();
        qtBrush = getBrushStyle(brushStyle);

        rectWidth = ui->wBox->value();

        mySquare = new Square(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, properID::UNIQUE_ID, rectWidth, points[0].rx(), points[0].ry());
        break;

    case 6:
        width = ui->widthBox->value();
        color = ui->colorBox->currentText().toStdString();
        qtColor = getColor(color);

        brushColor = ui->colorBrushBox->currentText().toStdString();
        qtBColor = getColor(brushColor);

        style = ui->styleBox->currentText().toStdString();
        qtStyle = getPenStyle(style);

        cap = ui->capBox->currentText().toStdString();
        qtCap = getPCStyle(cap);

        join = ui->joinBox->currentText().toStdString();
        qtJoin = getPJStyle(join);

        brushStyle = ui->styleBrushBox->currentText().toStdString();
        qtBrush = getBrushStyle(brushStyle);

        rectWidth = ui->wBox->value();
        length = ui->lBox->value();

        myEllipse = new Ellipse(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, properID::UNIQUE_ID, rectWidth, length, points[0].rx(), points[0].ry());

        break;

    case 7:
        width = ui->widthBox->value();
        color = ui->colorBox->currentText().toStdString();
        qtColor = getColor(color);

        brushColor = ui->colorBrushBox->currentText().toStdString();
        qtBColor = getColor(brushColor);

        style = ui->styleBox->currentText().toStdString();
        qtStyle = getPenStyle(style);

        cap = ui->capBox->currentText().toStdString();
        qtCap = getPCStyle(cap);

        join = ui->joinBox->currentText().toStdString();
        qtJoin = getPJStyle(join);

        brushStyle = ui->styleBrushBox->currentText().toStdString();
        qtBrush = getBrushStyle(brushStyle);

        radius = ui->wBox->value();

        myCircle = new Circle(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, properID::UNIQUE_ID, radius, points[0].rx(), points[0].ry());
        break;

    case 8:
        string weight;
        string style;
        string fontFamily;
        string align;
        string text;
        width = ui->widthBox->value(); // This is text point
        color = ui->colorBox->currentText().toStdString();
        qtColor = getColor(color);

        weight = ui->colorBrushBox->currentText().toStdString();

        style = ui->styleBox->currentText().toStdString();

        fontFamily = ui->styleBrushBox->currentText().toStdString();

        align = ui->joinBox->currentText().toStdString();

        rectWidth = ui->wBox->value();
        length = ui->lBox->value();

        text = ui->textLine->text().toStdString();

        myText = new Text(black, qtColor, SolidLine, FlatCap, MiterJoin, SolidPattern, width, properID::UNIQUE_ID, align, fontFamily, style, weight, text, points[0].rx(), points[0].ry(), length, rectWidth);

        break;

    /*default:
        qDebug() << "ERROR loading UI";
        break;(*/

    }

    answer = true;
    hide();
}

void confirmpage::onCancelClick()
{
    answer = false;
    hide();
}

void confirmpage::onAddClick()
{
    if(pointCount != maxPoints )
    {
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(2);

    QPoint add;
    int x;
    int y;
    QString xString;
    QString yString;

    x = ui->pointBoxX->value();
    y = ui->pointBoxY->value();
    add.setX(x);
    add.setY(y);

    xString =  QString::number(x);
    yString = QString::number(y);

    QTableWidgetItem *newItemOne = new QTableWidgetItem(xString);
    QTableWidgetItem *newItemTwo = new QTableWidgetItem(yString);

    points.push_back(add);
    ui->tableWidget->setItem(pointCount, 1, newItemOne);
    ui->tableWidget->setItem(pointCount - 1 , 2, newItemTwo);

        pointCount++;
    }

    if(pointCount == (maxPoints))
    {
       QString text = QString::number(maxPoints);
       QString labelText = "Only " + text + " point(s) can be added !";
       ui->warning->setText(labelText);
    }


}


