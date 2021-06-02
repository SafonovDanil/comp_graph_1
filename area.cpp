#include "area.h"
Area::Area(QWidget *parent):QWidget(parent)
{
setFixedSize(QSize(600,600));
myrect=new MyRect(250,0,50);
mypoint=new MyPoint(250, 0, 50);
myline=new MyLine(250,0,50);
alpha=0;
beta=0;
}
void Area::showEvent(QShowEvent *)
{
 myTimer=startTimer(20); // создать таймер
}
void Area::paintEvent(QPaintEvent *)
{
 QPainter painter(this);
 painter.setRenderHint(QPainter::Antialiasing);
 painter.setPen(Qt::black);
 painter.translate(300, 300);


 painter.rotate(beta);
 myrect->move(alpha,&painter);


 painter.setPen(QPen(Qt::DashLine));
 myline->move(alpha,&painter);


 painter.setPen(QPen(Qt::red,3,Qt::SolidLine));
 mypoint->move(alpha,&painter);
}
void Area::timerEvent(QTimerEvent *event)
{
 if (event->timerId() == myTimer && beta>-360) // если наш таймер
 {
 alpha-=0.05;
 beta-=1;
 update(); // обновить внешний вид
 }

 else
 QWidget::timerEvent(event); // иначе передать для стандартной
 // обработки
}
void Area::hideEvent(QHideEvent *)
{
killTimer(myTimer); // уничтожить таймер
}
Area::~Area()
{
 delete myrect;
 delete mypoint;
}
