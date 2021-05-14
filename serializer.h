#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "shape.h"
#include "line.h"
#include "circle.h"
#include "polygon.h"
#include "polyline.h"
#include "rectangle.h"
#include "square.h"
#include "ellipse.h"
#include "text.h"
#include "vector.h"
#include <ostream>

/**
 * @brief operator<<()
 * overloads the output stream operator so that a shape vector
 * can be output
 */
std::ostream& operator<<(std::ostream& out, myVec::vector<Shape*> &shapes);

/**
 * @brief brushToString()
 * changes qt brush style to
 * a string
 */
string brushToString(QBrush brush);

/**
 * @brief PJtoString()
 * changes qt pen join style to a string
 */
string PJtoString(QPen join);

/**
 * @brief PCtoString()
 * changes a qt pencap style
 * to a string
 */
string PCtoString(QPen cap);

/**
 * @brief penToString()
 * changes a qt pen style
 * to string
 */
string penToString(QPen style);

/**
 * @brief colorToString()
 * changes a qtcolor to string
 */
string colorToString(QColor color);

/**
 * @brief fontWeightToString()
 * changes a qt font weight to string
 */
string fontWeightToString(QFont fontWeight);

/**
 * @brief fontStyleToString()
 * changes a font style to string
 */
string fontStyleToString(QFont fontStyle);

/**
 * @brief alignToString()
 * changes an alignment type to a string
 *
 */
string alignToString(AlignmentFlag alignment);

#endif // SERIALIZER_H
