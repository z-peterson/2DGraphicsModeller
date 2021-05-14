#include "text.h"
#include <QDebug>

Text::Text()
     :Shape()
{
    align = AlignCenter;
    textString = " ";
    font.setWeight(QFont::Thin);
    startPoint.setX(0);
    startPoint.setY(0);
    length = 0;
    width = 0;
    shapeName = "Text";
}

Text::Text(const QColor &bColor, const QColor &color, const PenStyle &Pstyle, const PenCapStyle &PCstyle, const PenJoinStyle &PJstyle, const BrushStyle &Bstyle, int width, int id, string alignment, string fontFam, string fontStyle, string weight, string text, int x, int y, int textL, int textW)
     :Shape(bColor, color, Pstyle, PCstyle, PJstyle, Bstyle, width, id)
{
    //in this case, width is texpoint size

    setFontStyle(fontStyle);
    setFontFamily(fontFam);
    setTextAlignment(alignment);
    setFontWeight(weight);
    setTextPointSize(width);

    textString = QString::fromStdString(text);
    startPoint.setX(x);
    startPoint.setY(y);
    length = textL;
    this->width = textW;


    shapeName = "Text";

}

Text::~Text(){
    
}

void Text::draw(QPaintDevice* device) //needs change
{
    painter.begin(device);
    painter.drawText(startPoint + QPoint{length/3 , 0}, QString("ID: %1").arg(getShapeID()));
    qDebug() << startPoint;
    painter.setPen(getPen());
    painter.setFont(font);
    painter.drawText(getCenterPointX(), getCenterPointY(), getLength(), getWidth(), align, textString);
    painter.end();

}


void Text::move(int x, int y)
{

    setCenterPoint(x, y);
}

int Text::getCenterPointX()
{
    return startPoint.rx();
}

int Text::getCenterPointY()
{
    return startPoint.ry();
}

int Text::getLength()
{
    return length;
}

int Text::getWidth()
{
    return width;
}

void Text::setCenterPoint(int xCoord, int yCoord)
{
    startPoint.setX(xCoord);
    startPoint.setY(yCoord);
}

void Text::setLength(int lengthValue)
{
    length = lengthValue;
}

void Text::setWidth(int widthValue)
{
    width = widthValue;
}

void Text::setTextString(string text)
{
    textString = QString::fromStdString(text);
}

void Text::setTextAlignment(string alignment)
{
    if( alignment == " AlignLeft")
    {
        align = AlignLeft;
    }
    else if( alignment == " AlignRight")
    {
        align = AlignRight;
    }
    else if(alignment == " AlignTop")
    {
        align = AlignTop;
    }
    else if(alignment == " AlignBottom")
    {
        align = AlignBottom;
    }
    else if(alignment == " AlignCenter")
    {
        align = AlignCenter;
    }

}

void Text::setTextPointSize(int pointSize)
{
    font.setPointSize(pointSize);
}

void Text::setTextColor(string color){
   //unfinished
}

void Text::setFontFamily(string fontFamily){
    if(fontFamily == " Comic Sans MS"){
        font.setFamily(QString("Comic Sans MS"));
    }
    else if(fontFamily == " Courier"){
        font.setFamily(QString("Courier"));
    }
    else if(fontFamily == " Helvetica"){
        font.setFamily(QString("Helvetica"));
    }
    else if(fontFamily == " Times"){
        font.setFamily(QString("Times"));
    }
    else{
        font.setFamily(QString("Comic Sans MS"));
    }
}
                     
void Text::setFontStyle(string fontStyle){
    if(fontStyle == " StyleNormal"){
        font.setStyle(QFont::StyleNormal);
    }
    else if(fontStyle == " StyleItalic"){
        font.setStyle(QFont::StyleItalic);
    }
    else if(fontStyle == " StyleOblique"){
        font.setStyle(QFont::StyleOblique);
    }
    else{
        font.setStyle(QFont::StyleNormal);
    }

}
         
void Text::setFontWeight(string fontWeight){
    if(fontWeight == " Thin"){
        font.setWeight(QFont::Thin);
    }
    else if(fontWeight == " Light"){
        font.setWeight(QFont::Light);
    }
    else if(fontWeight == " Normal"){
        font.setWeight(QFont::Normal);
    }
    else if(fontWeight == " Medium"){
        font.setWeight(QFont::Medium);
    }
    else if(fontWeight == " Bold"){
        font.setWeight(QFont::Bold);
    }
    else if(fontWeight == " ExtraBold"){
        font.setWeight(QFont::ExtraBold);
    }
    else if(fontWeight == " Black"){
        font.setWeight(QFont::Black);
    }
    else{
        font.setWeight(QFont::Normal);
    }
}
            
