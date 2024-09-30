#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "Point.h"

class Rectangle
{
private:
    Point upLeft;
    Poinr lowRight;
public:
    boolInitMembers(const Point &ul, const Point &lr);
    void ShowRecInfo() const;    
};
#endif