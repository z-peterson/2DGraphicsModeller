#include "fileparser.h"
#include <QColor>

const QMap<int, string> SHAPE_NAMES
{
    {1, "Line"},
    {2, "Polyline"},
    {3, "Polygon"},
    {4, "Rectangle"},
    {5, "Square"},
    {6, "Ellipse"},
    {7, "Circle"},
    {8, "Text"},
};

myVec::vector<Shape*> ParseFile(int size)
{
    ifstream inFile;

    inFile.open("C:/Users/Zac/Desktop/CS1C-2D/shapes.txt"); // change path for diff computers !!!

    qDebug() << inFile.is_open();


    myVec::vector<Shape*> returnShapes(size);
    int id = 0;
    while(inFile)
    {
        string temp;

        inFile.ignore(numeric_limits<streamsize>::max(), ':');
        inFile >> id;
        inFile.ignore(numeric_limits<streamsize>::max(), ':');

        inFile >> temp;
        qDebug() << QString::fromStdString(temp);

        int universalID = SHAPE_NAMES.key(temp);

        if(inFile.eof())
        {
            break;
        }

        switch(universalID)
        {
        case 1: // line
            qDebug() << "CASE 1" ;
            returnShapes.push_back(readLine(inFile, id));
            break;

        case 2:// Polyline
            qDebug() << "CASE 2" ;
            returnShapes.push_back(readPolyLine(inFile, id));
            break;

        case 3:// Polygon
            qDebug() << "CASE 3" ;
            returnShapes.push_back(readPolygon(inFile, id));
            break;

        case 4:// Rectangle
            qDebug() << "CASE 4" ;
            returnShapes.push_back(readRectangle(inFile, id));
            break;

        case 5:// Square
            qDebug() << "CASE 5" ;
            returnShapes.push_back(readSquare(inFile, id));
            break;

        case 6:// Ellipse
            qDebug() << "CASE 6" ;
            returnShapes.push_back(readEllipse(inFile, id));
            break;

        case 7:// Circle
            qDebug() << "CASE 7" ;
            returnShapes.push_back(readCircle(inFile, id));
            break;

        case 8:// Text
            qDebug() << "CASE 8" ;
            returnShapes.push_back(ReadText(inFile, id));
            break;

        default:
            qDebug()<< "Error parsing file!!";
            break;
        }
    }

            inFile.close();

    return returnShapes;
}


Shape* readLine(ifstream &inFile, int id)
{
    int x, y, x2, y2, width;
    string color, style, cap, join;
    QColor qtColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    BrushStyle qtBrush = NoBrush;

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    inFile >> x;
    inFile.ignore(numeric_limits<streamsize>::max(), ',');
    inFile >> y;
    inFile.ignore(numeric_limits<streamsize>::max(), ',');
    inFile >> x2;
    inFile.ignore(numeric_limits<streamsize>::max(), ',');
    inFile >> y2;

    QPoint front(x, y);
    QPoint end(x2, y2);

    inFile.ignore(numeric_limits<streamsize>::max(), ':'); // get color
    getline(inFile, color);
    qtColor = getColor(color);

    inFile.ignore(numeric_limits<streamsize>::max(), ':'); // get width
    inFile >> width;

    inFile.ignore(numeric_limits<streamsize>::max(), ':'); // get style
    getline(inFile, style);
    qtStyle = getPenStyle(style);

    inFile.ignore(numeric_limits<streamsize>::max(), ':'); // get cap
    getline(inFile, cap);
    qtCap = getPCStyle(cap);

    inFile.ignore(numeric_limits<streamsize>::max(), ':'); // get join
    getline(inFile, join);
    qtJoin = getPJStyle(join);


    Line *line = new Line(qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, front, end);
    return line;
}

Shape* readPolyLine(ifstream &inFile, int id)
{
    int width;
    string color, style, cap, join;
    QColor qtColor, qtBColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    BrushStyle qtBrush = NoBrush;

    vector<QPoint> points;


    inFile.ignore(numeric_limits<streamsize>::max(), ':');

    do{
        int x, y;
        QPoint add;
        inFile.get();
        inFile >> x;
        inFile.get();
        inFile >> y;

        add.setX(x);
        add.setY(y);
        points.push_back(add);

    }while(inFile.peek() == ',');

     inFile.ignore(numeric_limits<streamsize>::max(), ':');
     getline(inFile, color);
     qtColor = getColor(color);

     inFile.ignore(numeric_limits<streamsize>::max(), ':');
     inFile >> width;

     inFile.ignore(numeric_limits<streamsize>::max(), ':');
     getline(inFile, style);
     qtStyle = getPenStyle(style);

     inFile.ignore(numeric_limits<streamsize>::max(), ':');
     getline(inFile, cap);
     qtCap = getPCStyle(cap);

     inFile.ignore(numeric_limits<streamsize>::max(), ':');
     getline(inFile, join);
     qtJoin = getPJStyle(join);

    Polyline *polyline = new Polyline(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, points);

    return polyline;
}

Shape* readPolygon(ifstream &inFile, int id)
{
    int width;
    string color, style, cap, join, bStyle, bColor;
    vector<QPoint> points;

    QColor qtColor, qtBColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    BrushStyle qtBrush;

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    do{
        int x, y;
        QPoint add;
        inFile.get();
        inFile >> x;
        inFile.get();
        inFile >> y;

        add.setX(x);
        add.setY(y);
        points.push_back(add);

    }while(inFile.peek() == ',');

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, color);
    qtColor = getColor(color);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    inFile >> width;

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, style);
    qtStyle = getPenStyle(style);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, cap);
    qtCap = getPCStyle(cap);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, join);
    qtJoin = getPJStyle(join);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, bColor);
    qtBColor = getColor(bColor);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, bStyle);
    qtBrush = getBrushStyle(bStyle);

    Polygon *polygon = new Polygon(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, points);

    return polygon;
}


Shape* readRectangle(ifstream& inFile, int id)
{
    int x, y, width;
    int l, w;
    string color, style, cap, join, brushStyle, brushColor;

    QColor qtColor, qtBColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    BrushStyle qtBrush;

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    inFile >> x;
    inFile.ignore(numeric_limits<streamsize>::max(), ',');
    inFile >> y;


    inFile.ignore(numeric_limits<streamsize>::max(), ',');
    inFile >> l;
    inFile.ignore(numeric_limits<streamsize>::max(), ','); // right here
    inFile >> w;

    QPoint point(x, y);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, color);
    qtColor = getColor(color);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    inFile >> width;

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, style);
    qtStyle = getPenStyle(style);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, cap);
    qtCap = getPCStyle(cap);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, join);
    qtJoin = getPJStyle(join);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, brushColor);
    qtBColor = getColor(brushColor);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, brushStyle);
    qtBrush = getBrushStyle(brushStyle);

    Rectangle *rectangle = new Rectangle(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, l, w, x , y);

    return rectangle;
}

Shape* readSquare(ifstream& inFile, int id)
{
    int x, y, width;
    int w;
    string color, style, cap, join, brushStyle, brushColor;

    QColor qtColor, qtBColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    BrushStyle qtBrush;


    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    inFile >> x;
    inFile.ignore(numeric_limits<streamsize>::max(), ',');
    inFile >> y;

    inFile.ignore(numeric_limits<streamsize>::max(), ',');
    inFile >> w;

    QPoint point(x, y);


    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, color);
    qtColor = getColor(color);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    inFile >> width;

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, style);
    qtStyle = getPenStyle(style);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, cap);
    qtCap = getPCStyle(cap);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, join);
    qtJoin = getPJStyle(join);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, brushColor);
    qtBColor = getColor(brushColor);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, brushStyle);
    qtBrush = getBrushStyle(brushStyle);

    Square *square = new Square(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, w, x , y);

    return square;
}

Shape* readEllipse(ifstream& inFile, int id)
{
    int x, y, width;
    int a, b;
    string color, style, cap, join, brushStyle, brushColor;

    QColor qtColor, qtBColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    BrushStyle qtBrush;

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    inFile >> x;
    inFile.ignore(numeric_limits<streamsize>::max(), ',');
    inFile >> y;

    inFile.ignore(numeric_limits<streamsize>::max(), ',');
    inFile >> a;
    inFile.ignore(numeric_limits<streamsize>::max(), ',');
    inFile >> b;

    QPoint point(x, y);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, color);
    qtColor = getColor(color);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    inFile >> width;

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, style);
    qtStyle = getPenStyle(style);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, cap);
    qtCap = getPCStyle(cap);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, join);
    qtJoin = getPJStyle(join);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, brushColor);
    qtBColor = getColor(brushColor);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, brushStyle);
    qtBrush = getBrushStyle(brushStyle);


    Ellipse *ellipse = new Ellipse(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, a, b, x, y ); // need qtBrushColor as well!!!!

    return ellipse;
}

Shape* readCircle(ifstream& inFile, int id)
{
    int x, y, width;
    int r;
    string color, style, cap, join, brushStyle, brushColor;

    QColor qtColor, qtBColor;
    PenStyle qtStyle;
    PenCapStyle qtCap;
    PenJoinStyle qtJoin;
    BrushStyle qtBrush;

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    inFile >> x;
    inFile.ignore(numeric_limits<streamsize>::max(), ',');
    inFile >> y;

    inFile.ignore(numeric_limits<streamsize>::max(), ',');
    inFile >> r;

    //QPoint point(x + r, y + r); idk yet

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, color);
    qtColor = getColor(color);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    inFile >> width;

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, style);
    qtStyle = getPenStyle(style);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, cap);
    qtCap = getPCStyle(cap);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, join);
    qtJoin = getPJStyle(join);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, brushColor);
    qtBColor = getColor(brushColor);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, brushStyle);
    qtBrush = getBrushStyle(brushStyle);
    qDebug() << qtBrush;

    Circle *circle = new Circle(qtBColor, qtColor, qtStyle, qtCap, qtJoin, qtBrush, width, id, r, x, y); // maybe change the little plus thingss x+ r y+ r??

    return circle;
}


Shape* ReadText(ifstream& inFile, int id)
{
    int x , y, fontPoint, length, width;

    string color, textLine, align, fontFamily, fontStyle, fontWeight;
    QColor qtColor;

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    inFile >> x;
    inFile.ignore(numeric_limits<streamsize>::max(), ',');
    inFile >> y;

    inFile.ignore(numeric_limits<streamsize>::max(), ',');
    inFile >> length;
    inFile.ignore(numeric_limits<streamsize>::max(), ',');
    inFile >> width;

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, textLine);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, color);
    qtColor = getColor(color);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, align);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    inFile >> fontPoint;

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, fontFamily);

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, fontStyle);
    fontStyle = " StyleNormal";

    inFile.ignore(numeric_limits<streamsize>::max(), ':');
    getline(inFile, fontWeight);

    Text *text = new Text(black, qtColor, SolidLine, FlatCap, MiterJoin, SolidPattern, fontPoint, id, align, fontFamily, fontStyle, fontWeight, textLine, x, y, length, width);

    return text;
}

QColor getColor(string color)
{
    if(color == " white"){
        return white;
    }
    else if(color == " black"){
        return black;
    }
    else if(color == " red"){
        return red;
    }
    else if(color == " green"){
        return green;
    }
    else if(color == " blue"){
        return blue;
    }
    else if(color == " cyan"){
        return cyan;
    }
    else if(color == " magenta"){
        return magenta;
    }
    else if(color == " yellow"){
        return yellow;
    }
    else if(color == " gray"){
        return gray;
    }

}

PenStyle getPenStyle(string style)
{
    if(style == " NoPen"){
        return NoPen;
    }
    else if(style == " SolidLine"){
        return SolidLine;
    }
    else if(style == " DashLine"){
        return DashLine;
    }
    else if(style == " DotLine"){
        return DotLine;
    }
    else if(style == " DashDotLine"){
        return DashDotLine;
    }
    else if(style == " DashDotDotLine"){
        return DashDotDotLine;
    }
}

PenCapStyle getPCStyle(string cap)
{
    if(cap == " FlatCap"){
        return FlatCap;
    }
    else if(cap == " SquareCap"){
        return SquareCap;
    }
    else if(cap == " RoundCap"){
        return RoundCap;
    }
}

PenJoinStyle getPJStyle(string join)
{
    if(join == " MiterJoin"){
        return MiterJoin;
    }
    else if(join == " BevelJoin"){
        return BevelJoin;
    }
    else if(join == " RoundJoin"){
        return RoundJoin;
    }
}

BrushStyle getBrushStyle(string brush)
{
    if(brush == " SolidPattern"){
        return SolidPattern;
    }
    else if(brush == " HorPattern"){
        return HorPattern;
    }
    else if(brush == " VerPattern"){
        return VerPattern;
    }
    else if(brush == " NoBrush"){
        return NoBrush;
    }
}

