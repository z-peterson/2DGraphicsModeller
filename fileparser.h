#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <iostream>
#include <fstream>
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

using namespace std;

/**
 * @brief ParseFile()
 * parses the file and adds shape
 * to shape vector
 */
myVec::vector<Shape*> ParseFile(int size);

/**
 * @brief readLine()
 * reads a line shape from the
 * text file
 */
Shape* readLine(ifstream &inFile, int id);

/**
 * @brief readPolyLine()
 * reads a polyline shape from
 * the text file
 */
Shape* readPolyLine(ifstream &inFile, int id);

/**
 * @brief readPolygon()
 * reads a polygon shape from the text file
 */
Shape* readPolygon(ifstream &inFile, int id);

/**
 * @brief readRectangle()
 * reads a rectangle shape from the text
 */
Shape* readRectangle(ifstream &inFile, int id);

/**
 * @brief readSquare()
 * reads square
 */
Shape* readSquare(ifstream &inFile, int id);

/**
 * @brief readEllipse()
 * reads ellipse
 */
Shape* readEllipse(ifstream &inFile, int id);

/**
 * @brief readCircle()
 * reads circle
 */
Shape* readCircle(ifstream &inFile, int id);

/**
 * @brief ReadText()
 * reads text
 */
Shape* ReadText(ifstream& inFile,int id);

/**
 * @brief getColor()
 * gets a Qcolor from a string
 */
QColor getColor(string color);

/**
 * @brief getPenStyle()
 * gets a pen style from a string
 */
PenStyle getPenStyle(string style);

/**
 * @brief getBrushStyle()
 * gets a brushstyle from a string
 */
BrushStyle getBrushStyle(string brush);
/**
 * @brief getPJStyle()
 * gets a pen joinstyle from
 * a string
 *
 */
PenJoinStyle getPJStyle(string join);
/**
 * @brief getPCStyle()
 * gets a pen cap style from a string
 *
 */
PenCapStyle getPCStyle(string cap);



#endif // FILEPARSER_H
