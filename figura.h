#ifndef figura_h
#define figura_h
#include <QtGui>
class Figura
{
protected:
 int x,y,halflen,dx,dy,r,xx = 300,yy= 300;
 virtual void draw(QPainter *Painter)=0;
public:

 Figura(int X,int Y,int Halflen):
 x(X),y(Y),halflen(Halflen){}
 void move(float Alpha,QPainter *Painter);
};


class MyRect:public Figura
{
protected:
 void draw(QPainter *Painter);
public:
 MyRect(int x,int y,int halflen):Figura(x,y,halflen){}
};


class MyPoint:public Figura
{
protected:
 void draw(QPainter *Painter);
public:
 MyPoint(int x,int y,int halflen):Figura(x,y,halflen){}
};

class MyLine:public Figura
{
protected:
    void draw(QPainter *Painter);
public:
    MyLine(int x,int y,int halflen):Figura(x,y,halflen){}
};

#endif
