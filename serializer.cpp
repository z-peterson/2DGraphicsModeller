#include "serializer.h"


std::ostream& operator<<(std::ostream& out, const QString &str)
{
    return out << str.toStdString();
}

std::ostream& operator<<(std::ostream& out, myVec::vector<Shape*> &shapes)
{
    for(Shape* shape : shapes)
    {
        out<< "ShapeId: " << shape->getShapeID() << "\n";
        out<< "ShapeType: " << shape->getShapeName() << "\n";
        out<< "ShapeDimensions: ";

#define TRY_CAST(type) auto* cast = dynamic_cast<type*>(shape)
        if(TRY_CAST(Line))
        {
            QPoint start = cast->getStart();
            QPoint end = cast->getEnd();

            out << start.x() << ", " << start.y() << ", " << end.x() << ", " << end.y() << "\n";
        }
        else if (TRY_CAST(Polyline))
        {
            vector <QPoint> store = cast->returnPoints();
            for(unsigned int i = 0; i < store.size(); i++)
            {
                out<< store[i].x() << ", " << store[i].y();
                if(i != (store.size() - 1))
                {
                    out<< ", ";
                }
            }
            out<< "\n";
        }
        else if(TRY_CAST(Polygon))
        {
            vector <QPoint> store = cast->returnPoints();
            for(unsigned int i = 0; i < store.size(); i++)
            {
                out<< store[i].x() << ", " << store[i].y();

                if(i != (store.size() - 1))
                {
                    out<< ", ";
                }

            }
            out<< "\n";

        }
        else if(TRY_CAST(Rectangle))
        {
            QPoint start = cast->getStart();
            int width = cast->getWidth();
            int length = cast->getLength();
            out << start.x() << ", " << start.y() << ", " << length << ", " << width << "\n";

        }
        else if(TRY_CAST(Square))
        {
            QPoint start = cast->getStart();
            int width = cast->getWidth();
            out << start.x() << ", " << start.y() << ", " << width << "\n";

        }
        else if(TRY_CAST(Ellipse))
        {
            QPoint start = cast->getStart();
            int a = cast->getA();
            int b =cast->getB();
            out<< start.x() << ", " << start.y() << ", " << a << ", " << b << "\n";

        }
        else if(TRY_CAST(Circle))
        {
            QPoint start = cast->getStart();
            int radius = cast->getRadius();
            out<< start.x() << ", " << start.y() << ", " << radius << "\n";

        }
        else if(TRY_CAST(Text))
        {
            QPoint start = cast->getStart();
            int w = cast->getWidth();
            int l = cast->getLength();

            out<< start.x() << ", " << start.y() << ", " << l << ", " << w << "\n";

        }

        if (shape->getShapeName() != "Text")
        {
            const QPen &pen = shape->getPen();
            out << "PenColor: " << colorToString(pen.color()) << "\n";
            out << "PenWidth: " << pen.width() << "\n";
            out << "PenStyle: " << penToString(pen) << "\n";
            out << "PenCapStyle: " << PCtoString(pen) << "\n";
            out << "PenJoinStyle: " << PJtoString(pen) << "\n";
        }

        if (shape->getShapeName() != "Text" && shape->getShapeName() != "Line" && shape->getShapeName() != "Polyline")
        {
            const QBrush &brush = shape->getBrush();
            out << "BrushColor: " << colorToString(brush.color()) << "\n";
            out << "BrushStyle: " << brushToString(brush) << "\n";
        }

        if (TRY_CAST(Text)) {
            const QFont &font = cast->getFont();
            out << "TextString: " << cast->getText() << "\n";
            out << "TextColor: " << colorToString(cast->getPen().color()) << "\n";
            out << "TextAlignment: " << alignToString(cast->getAlign())<< "\n";
            out << "TextPointSize: " << font.pointSize() << "\n";
            out << "TextFontFamily: " << font.family() << "\n";
            out << "TextFontStyle: " << fontStyleToString(font) << "\n";
            out << "TextFontWeight: " << fontWeightToString(font) << "\n";

            qDebug() << QString::fromStdString(fontStyleToString(font));
        }

        out<< "\n";
    }
}



string colorToString(QColor color)
{
    if(color == white){
        return "white";
    }
    else if(color == black){
        return "black";
    }
    else if(color == red){
        return "red";
    }
    else if(color == green){
        return "green";
    }
    else if(color == blue){
        return "blue";
    }
    else if(color == cyan){
        return "cyan";
    }
    else if(color == magenta){
        return "magenta";
    }
    else if(color == yellow){
        return "yellow";
    }
    else if(color == gray){
        return "gray";
    }

}

string penToString(QPen style)
{
    if(style.style() == NoPen){
        return "NoPen";
    }
    else if(style.style() == SolidLine){
        return "SolidLine";
    }
    else if(style.style() == DashLine){
        return "DashLine";
    }
    else if(style.style() == DotLine){
        return "DotLine";
    }
    else if(style.style() == DashDotLine){
        return "DashDotLine";
    }
    else if(style.style() == DashDotDotLine){
        return "DashDotDotLine";
    }
}

string PCtoString(QPen cap)
{
    if(cap.capStyle() == FlatCap){
        return "FlatCap";
    }
    else if(cap.capStyle() == SquareCap){
        return "SquareCap";
    }
    else if(cap.capStyle() == RoundCap){
        return "RoundCap";
    }
}

string PJtoString(QPen join)
{
    if(join.joinStyle() == MiterJoin){
        return "MiterJoin";
    }
    else if(join.joinStyle() == BevelJoin){
        return "BevelJoin";
    }
    else if(join.joinStyle() == RoundJoin){
        return "RoundJoin";
    }
}

string brushToString(QBrush brush)
{
    if(brush.style() == SolidPattern){
        return "SolidPattern";
    }
    else if(brush.style() == HorPattern){
        return "HorPattern";
    }
    else if(brush.style() == VerPattern){
        return "VerPattern";
    }
    else if(brush.style() == NoBrush){
        return "NoBrush";
    }
}

string alignToString(AlignmentFlag alignment)
{
    if( alignment == AlignLeft)
    {
       return "AlignLeft";
    }
    else if( alignment == AlignRight)
    {
        return "AlignRight";
    }
    else if(alignment == AlignTop)
    {
        return "AlignTop";
    }
    else if(alignment == AlignBottom)
    {
        return "AlignBottom";
    }
    else if(alignment == AlignCenter)
    {
        return "AlignCenter";
    }

}

string fontStyleToString(QFont fontStyle)
{
    if(fontStyle.style() == QFont::StyleNormal)
    {
        return "StyleNormal";
    }
    else if(fontStyle.style() == QFont::StyleItalic)
    {
        return "StyleItalic";
    }
    else if(fontStyle.style() == QFont::StyleOblique)
    {
        return "StyleOblique";
    }


}

string fontWeightToString(QFont fontWeight)
{
    if(fontWeight.weight() == QFont::Thin)
    {
        return "Thin";
    }
    else if(fontWeight.weight() == QFont::Light)
    {
        return "Light";
    }
    else if(fontWeight.weight() == QFont::Normal)
    {
        return "Normal";
    }
    else if(fontWeight.weight() == QFont::Medium)
    {
        return "Medium";
    }
    else if(fontWeight.weight() == QFont::Bold)
    {
        return "Bold";
    }
    else if(fontWeight.weight() == QFont::ExtraBold)
    {
        return "ExtraBold";
    }
    else if(fontWeight.weight() == QFont::Black)
    {
        return "Black";
    }

}
