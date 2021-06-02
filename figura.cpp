#include <math.h>
#include "figura.h"
void Figura::move(float Alpha,QPainter *Painter)
{
 dx=halflen*sin(Alpha);
 dy=halflen*cos(Alpha);
 draw(Painter);
}

void MyRect::draw(QPainter *Painter)
{
 Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
 Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
 Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
 Painter->drawLine(x-dy,y+dx,x+dx,y+dy);

}

void MyPoint::draw(QPainter *Painter)
{
 Painter->drawLine(x+dx,y+dy, x+dx,y+dy);
}

void MyLine::draw(QPainter *Painter)
{
 Painter->drawLine(0,0, x,y);
}
