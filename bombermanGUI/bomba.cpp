#include "bomba.h"

bomba::bomba()
{

}

bomba::~bomba()
{

}

bomba::bomba(int x, int y, int lado)
{
    //Permite ubicar la bomba dentro de la cuadricula correctamente
    int nx = x/48;
    int ny = y/48;
    this->posx=nx*48;
    this->posy=ny*48;
    this->lado=lado;
    setPos(posx,posy);
}

QRectF bomba::boundingRect() const
{
    return QRectF(0,0,lado,lado);
}

void bomba::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pxMap(":/images/bomba.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}
