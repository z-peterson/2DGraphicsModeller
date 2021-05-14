#ifndef TEXT_H
#define TEXT_H

#include "shape.h"
#include <string>

/**
 * @brief Text
 * text class
 * inherits from shape
 */
class Text: public Shape
{
public:
    /**
     * @brief Text()
     * default constructor
     */
    Text();

    /**
     * @brief Text()
     * paramaterized constructor
     */
    Text(const QColor &bColor, const QColor &color, const PenStyle &Pstyle, const PenCapStyle &PCstyle, const PenJoinStyle &PJstyle, const BrushStyle &Bstyle, int width, int id, string alignment, string fontFam, string fontStyle, string weight, string text, int x, int y, int textL, int textW);

    /**
     * @brief ~Text()
     * destructor
     */
    ~Text();

    /**
     * @brief draw()
     * draw the shape to the canvas
     */
    virtual void draw(QPaintDevice* device);

    /**
     * @brief move()
     * move the shape on the canvas
     */
    virtual void move(int x, int y);
    

    /**
     * @brief getCenterPointX()
     * return the center point's
     * x value
     */
    int getCenterPointX();

    /**
     * @brief getCenterPointY()
     * return the center point's
     * y location
     */
    int getCenterPointY();

    /**
     * @brief getLength()
     * return the length
     */
    int getLength();

    /**
     * @brief getWidth()
     * return the width
     */
    int getWidth();

    /**
     * @brief getAlign()
     * return the alignment
     */
    AlignmentFlag getAlign(){return align;};

    /**
     * @brief getFont()
     * Return the font
     */
    QFont getFont(){return font;};

    /**
     * @brief getText()
     * return the string
     * containing the displayed
     * text
     */
    QString getText(){return textString;};


    /**
     * @brief setCenterPoint()
     * set the center point
     * of the text
     */
    void setCenterPoint(int xCoord, int yCoord);

    /**
     * @brief setLength()
     * set the length of the text
     */
    void setLength(int lengthValue);

    /**
     * @brief setWidth()
     * set the width of the text
     */
    void setWidth(int widthValue);

    /**
     * @brief setTextString()
     * set the string of the text  to
     * be displayed
     */
    void setTextString(string text);

    /**
     * @brief setTextAlignment()
     * set text alignment
     */
    void setTextAlignment(string alignment);

    /**
     * @brief setTextPointSize()
     * set the text point size
     */
    void setTextPointSize(int pointSize);

    /**
     * @brief setTextColor()
     * set the text colr
     */
    void setTextColor(string color);

    /**
     * @brief setFontFamily()
     * set the font family
     */
    void setFontFamily(string fontFamily);

    /**
     * @brief setFontStyle()
     * set the font style
     */
    void setFontStyle(string fontStyle);

    /**
     * @brief setFontWeight()
     * set the weight
     */
    void setFontWeight(string fontWeight);


    /**
     * @brief getStart()
     * get the start point of the text
     */
    QPoint getStart(){return startPoint;};
    
private:
    AlignmentFlag align;
    QString textString;
    QFont font;
    QPoint startPoint;
    int length;
    int width;

    
};

#endif // TEXT_H
